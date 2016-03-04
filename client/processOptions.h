/*======================================================
    > File Name: login.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月01日 星期二 23时44分01秒
 =======================================================*/
#pragma once

#include "codec.h"
#include <google/protobuf/message.h>
#include "connection.h"
#include <thread>
#include <functional>

//codec_的回调
typedef std::shared_ptr<google::protobuf::Message> messagePtr;
void onMessage(const netlib::connectionPtr &conn,const messagePtr &message){}

class ProcessOptions
{
    public:
        ProcessOptions(int conn)
            :conn_(conn),
            codec_(onMessage),
            recvThread_(&ProcessOptions::sendChatMessage,this)
        {}       
        //处理登陆
        bool handleLogin(void);
        //处理注册
        bool handleRegister(void);
        //注册房间
        bool handleRegisterRoom(void);
        //进入房间
        bool handleEnterRoom(void);
        //发送消息
        bool sendChatMessage(void);
        //接受消息
        bool recvChatMessage(void);
    private:
        int conn_;    //与服务器的连接socket
        ProtobufCodec codec_;
        std::thread recvThread_;       
};
