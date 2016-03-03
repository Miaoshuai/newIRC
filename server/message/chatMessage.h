/*======================================================
    > File Name: chatMessage.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年02月18日 星期四 23时43分20秒
 =======================================================*/
#pragma once
#include <mutex>
#include "message.h"

//分发消息
void distributeMessage(MessageType::ChatMessagePtr &message,MessageType::RoomMap rooms,ProtobufCodec &codec,std::string roomName)
{
    //获取连接队列智能指针的一份拷贝
    MessageType::ConnectionListPtr conns;
    MessageType::ConnectionsClass connections = rooms[roomName];
    {
        std::lock_guard<std::mutex> guard((*connections.mutex_));
        conns = connections.connections_;  
    }
    //给每一个在线用户发送此消息
    for(auto conn : *conns)
    {
        codec.fillEmptyBuffer(&conn->outputBuffer_,*message);
        conn->send();       
    }    
}

//获得完整消息
std::string getCompleteMessage(std::string name,MessageType::ChatMessagePtr &message)
{
    std::string newMessage;
    newMessage = newMessage + name + ":" + message->chat_message();
    return newMessage;
}

