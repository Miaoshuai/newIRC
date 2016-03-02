/*======================================================
    > File Name: server.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月31日 星期日 13时54分49秒
 =======================================================*/
#include "codec.h"
#include "dispatcher.h"
#include "message.pb.h"
#include "server.h"
#include "connection.h"
#include "message.h"
#include "mysql.h"

#include <string>
#include <iostream>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>
#include <list>

typedef std::shared_ptr<Login> LoginPtr;
typedef std::shared_ptr<Register> RegisterPtr;

class IrcServer
{
    public:
        IrcServer(std::string ip,std::string port)
            :server_(ip,atoi(port.c_str()),4),
            codec_(std::bind(&ProtobufDispatcher::onProtobufMessage,&dispatcher_,std::placeholders::_1,std::placeholders::_2)),
            sql_("127.0.0.1","root","kaiji","school"),
            messageType_(codec_,sql_,connections_,users_)

    {
        dispatcher_.registerMessageCallback<Login>(std::bind(&MessageType::onLogin,&messageType_,std::placeholders::_1,std::placeholders::_2));
        dispatcher_.registerMessageCallback<Register>(std::bind(&MessageType::onRegister,&messageType_,std::placeholders::_1,std::placeholders::_2));
        server_.setMessageCallback(std::bind(&ProtobufCodec::onMessage,&codec_,std::placeholders::_1,std::placeholders::_2));
    }
        void start(void)
        {
            server_.start();
        }
    private:
        //填充
        void fillUserMap(void)
        {
            MYSQL_ROW row;
            sql_.operate("select *from user");
            while((row = sql_.getRow()) != NULL)
            {
                (*users_)[row[0]] = row[1];       
            }      
        }

        typedef std::shared_ptr<std::list<netlib::connectionPtr>> ConnectionListPtr;
        typedef std::shared_ptr<std::map<std::string,std::string>> UserMapPtr;
        
        UserMapPtr users_;                  //初始化时从数据库中读出所有的用户和对应密码保存到user_中
        ConnectionListPtr connections_;    //保存现有连接
        netlib::Server server_;
        ProtobufCodec codec_;  
        ProtobufDispatcher dispatcher_;
        MessageType messageType_;       //消息类型处理函数类
        Sql sql_;       
};


int main(int argc,char **argv)
{
    IrcServer server(argv[1],argv[2]);
    server.start();
    return 0;
}


