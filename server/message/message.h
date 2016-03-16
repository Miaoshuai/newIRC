/*======================================================
    > File Name: message.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年02月15日 星期一 20时15分22秒
 =======================================================*/
/*各种消息处理函数*/

#pragma once

#include <memory>
#include "connection.h"
#include "message.pb.h"
#include "codec.h"
#include "mysql.h"
#include <list>
#include <string>
#include <mutex>
#include <stdio.h>

class MessageType
{
    public:
        typedef std::shared_ptr<Login> LoginPtr;
        typedef std::shared_ptr<Register> RegisterPtr;
        typedef std::shared_ptr<ChatMessage> ChatMessagePtr;
        typedef std::shared_ptr<RegisterRoom> RegisterRoomPtr;
        typedef std::shared_ptr<EnterRoom> EnterRoomPtr;

        typedef std::list<netlib::connectionPtr> ConnectionList;
        typedef std::shared_ptr<std::list<netlib::connectionPtr>> ConnectionListPtr;
        class ConnectionsClass
        {
            public:
                ConnectionsClass()
                    :connections_(new std::list<netlib::connectionPtr>),
                    mutex_(new std::mutex)
                {
                }
                std::mutex *mutex_;
                ConnectionListPtr connections_;
        };
        typedef std::map<std::string,ConnectionsClass> RoomMap;
        MessageType(ProtobufCodec &codec)
            :codec_(codec),
            sql_("127.0.0.1","root","kaiji","IRC")
        {
        }

        //处理聊天消息
        void onChatMessage(netlib::connectionPtr conn,ChatMessagePtr message);

        //处理登陆消息
        void onLogin(netlib::connectionPtr conn,LoginPtr message);

        //处理注册消息
        void onRegister(netlib::connectionPtr conn,RegisterPtr message);

        //处理注册房间消息
        void onRegisterRoom(netlib::connectionPtr conn,RegisterRoomPtr message);

        //处理加入房间的消息
        void onEnterRoom(netlib::connectionPtr conn,EnterRoomPtr message);
    private:
        Sql sql_;   //数据库
        RoomMap rooms_;
        ProtobufCodec codec_;
};
