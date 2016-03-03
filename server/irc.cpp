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
typedef std::shared_ptr<ChatMessage> ChatMessagePtr;
typedef std::shared_ptr<Room> RoomPtr;

class IrcServer
{
    public:
        IrcServer(std::string ip,std::string port)
            :server_(ip,atoi(port.c_str()),4),
            codec_(std::bind(&ProtobufDispatcher::onProtobufMessage,&dispatcher_,std::placeholders::_1,std::placeholders::_2)),
            sql_("127.0.0.1","root","kaiji","school"),
            messageType_(codec_,sql_)

    {
        dispatcher_.registerMessageCallback<Login>(std::bind(&MessageType::onLogin,&messageType_,std::placeholders::_1,std::placeholders::_2));
        dispatcher_.registerMessageCallback<Register>(std::bind(&MessageType::onRegister,&messageType_,std::placeholders::_1,std::placeholders::_2));
        dispatcher_.registerMessageCallback<ChatMessage>(std::bind(&MessageType::onChatMessage,&messageType_,std::placeholders::_1,std::placeholders::_2));
        dispatcher_.registerMessageCallback<Room>(std::bind(&MessageType::onRoom,&messageType_,std::placeholders::_1,std::placeholders::_2));
        server_.setMessageCallback(std::bind(&ProtobufCodec::onMessage,&codec_,std::placeholders::_1,std::placeholders::_2));
    }
        void start(void)
        {
            server_.start();
        }
    private:
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


