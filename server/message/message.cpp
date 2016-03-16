/*======================================================
    > File Name: message.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年02月15日 星期一 20时22分13秒
 =======================================================*/

#include "message.h"
#include "connection.h"
#include "codec.h"
#include "register.h"
#include "login.h"
#include "chatMessage.h"
#include "statusCode.h"
#include "enterRoom.h"
#include "registerRoom.h"
#include <iostream>
#include <assert.h>
#include <stdio.h>

void MessageType::onRegisterRoom(netlib::connectionPtr conn,RegisterRoomPtr message)
{
    Status status;
    std::cout<<"rename:"<<message->room_name()<<std::endl;
    //如果用户不存在
    if(!isRoomExist(message,sql_))
    {
        if(!registerRoom(message,sql_,conn))
        {
            status.set_create_room(ROOM::C_ROOM_FAIL);
        }
        else
        {
            status.set_create_room(ROOM::C_ROOM_SUCCEED);
        }
    }
    else
    {
        status.set_create_room(ROOM::C_ROOM_FAIL);
    }
    codec_.fillEmptyBuffer(&conn->outputBuffer_,status);
    conn->send();
}

void MessageType::onEnterRoom(netlib::connectionPtr conn,EnterRoomPtr message)
{
    Status status;
    if(!enterRoom(rooms_,conn,message,sql_))
    {
        status.set_enter_room(ROOM::E_ROOM_FAIL);
    }
    else
    {
        conn->rooName_ = message->room_name();
        status.set_enter_room(ROOM::E_ROOM_SUCCEED);
    }
    codec_.fillEmptyBuffer(&conn->outputBuffer_,status);
    conn->send();
}


void MessageType::onChatMessage(netlib::connectionPtr conn,ChatMessagePtr message)
{
    //获得完整消息，并将其填充成新message
    std::string recvMessage(getCompleteMessage(conn->ConnectionName_,message));
    ChatMessagePtr newMessage(new ChatMessage);
    newMessage->set_chat_message(recvMessage);
    //将消息发给每一个在线用户
    distributeMessage(newMessage,rooms_,codec_,conn->rooName_);        
}


void MessageType::onLogin(netlib::connectionPtr conn,LoginPtr message)
{
    Status status;
    std::cout<<"user_name:"<<message->user_name()<<std::endl;
    if(!checkUserAndPassword(message,sql_))
    {
        status.set_login(LOGIN::LOGIN_FAIL);      
    }
    else
    {
        status.set_login(LOGIN::LOGIN_SUCCEED);
        //设置conn的connectionName_
        conn->ConnectionName_ = message->user_name();
        printf("登陆成功\n");
    }
    codec_.fillEmptyBuffer(&conn->outputBuffer_,status);
    conn->send();   
}

void MessageType::onRegister(netlib::connectionPtr conn,RegisterPtr message)
{
    //判断该用户名是否已经存在
    Status status;   
    if(isUserExist(message,sql_))
    {
        if(!checkPassword(message))
        status.set_register_(REGISTER::REGISTER_FAIL);                       
    }
    else
    {
        status.set_register_(REGISTER::REGISTER_SUCCEED);
        //将新用户添加到user表中
        assert(registerUser(message,sql_));
    }
    codec_.fillEmptyBuffer(&conn->outputBuffer_,status);
    conn->send();    
}
