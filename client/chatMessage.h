/*======================================================
    > File Name: chatMessage.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月04日 星期五 13时15分45秒
 =======================================================*/
#pragma once

#include "message.pb.h"

//生成聊天消息
ChatMessage getChatMessage(void)
{
    std::string chatMessage;
    cin>>chatMessage;

    //生成聊天消息
    ChatMessage message;
    message.set_chat_message(chatMessage);
    return message;
}

int sendChat(const ProtobufCodec &codec,const int &conn,const ChatMessage &message)
{
    netlib::Buffer buf;
    codec.fillEmptyBuffer(&buf,message);

    int ret = send(conn,buf.getReadPeek(),buf.readableSize());
    return ret;
}
