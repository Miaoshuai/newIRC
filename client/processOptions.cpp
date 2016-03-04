/*======================================================
    > File Name: processOptions.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月01日 星期二 23时51分59秒
 =======================================================*/
#include "processOptions.h"

#include "message.pb.h"
#include "buffer.h"
#include "codec.h"
#include "connection.h"
#include "login.h"
#include "register.h"
#include <google/protobuf/message.h>
#include <functional>
#include <iostream>
#include <assert.h>



bool ProcessOptions::handleLogin(void)
{
    //进行登陆
    while(1)
    {
        //获得登陆消息
        Login message = getLoginMessage();
        //发送登陆消息
        assert(sendLoginMessage(codec_,conn_,message) >= 0);
        if(isLoginSucceed(conn_,codec_))
        {
            return true;
        }
    } 
    return false;
}

bool ProcessOptions::handleRegister(void)
{
   //进行注册
   while(1)
   {
        //获得注册消息
        Register message = getRegisterMessage();
        //发送注册消息
        assert(sendRegisterMessage(codec_,conn_,message) >=0);
        if(isRegisterSucceed(conn_,code_))
        {
            return true;
        }
   } 
   return false;
}

bool ProcessOptions::handleRegisterRoom(void)
{
    //注册房间
    while(1)
    {
        //获得注册消息
        Room message = getRegisterRoomMessage();
        //发送注册消息
        assert(sendRoomMessage(codec_,conn_,message) >= 0);
        if(isRegisterRoomSucceed(conn_,code_))
        {
            return true;
        }
    }    
    return false;
}

bool ProcessOptions::handleEnterRoom(void)
{
    //进入房间
    while(1)
    {
        //生成进入房间的消息
        Room message = getEnterRoomMessage();
        //发送进入房间消息
        assert(sendRoomMessage(codec_,conn_message) >= 0);
        if(isEnterRoomSucceed(conn_,code_))
        {
            return true;
        }
    }
    return false;
}

bool ProcessOptions::sendChatMessage(void)
{
    ChatMessage message;
    //获取聊天消息
    message = getChatMessage();
    //发送聊天消息
    assert(sendChat(codec_,conn_,message));
}

bool ProcessOptions::recvChatMessage(void)
{
    netlib::Buffer buf;
    MessagePtr message;

    //循环读取消息
    while(read(conn_,buf.getWritePeek(),buf.writeableSize()) >= 0)
    {
        message = codec_.getMessage(&buf);
        std::cout<<message->chatMessage()<<std::endl;    
    }
}
