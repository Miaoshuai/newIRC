/*======================================================
    > File Name: room.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月04日 星期五 09时48分50秒
 =======================================================*/
#pragma once

#include "message.pb.h"
#include "statusCode.h"
#include "codec.h"
#include <iostream>

//获得注册房间消息
Room getRegisterRoomMessage(void)
{
    std::cout<<"请输入房间名:"<<std::endl;
    std::string roomName;
    std::cin>>roomName;

    //生成注册房间消息
    Room message;
    message.set_what("create");
    message.set_room_name(roomName);
    return message;
}

Room getEnterRoomMessage(void)
{
    std::cout<<"请输入房间名:"<<std::endl;
    std::string roomName;
    std::cin>>roomName;

    //生成进入房间消息
    Room message;
    message.set_what("enter");
    message.set_room_name(roomName);
    return message;
}


int sendRoomMessage(const ProtobufCodec &codec,const int &conn,const Room &message)
{
    netlib::Buffer buf;
    codec.fillEmptyBuffer(&buf,message);

    int ret = send(conn,buf.getReadPeek(),buf.readableSize());
    return ret;
}

bool isRegisterRoomSucceed(const int &conn,const ProtobufCodec &codec)
{
    netlib::Buffer buf;
    int ret = read(conn,buf.getWritePeek(),buf.writeableSize());
    assert(ret >= 0);
    MessagePtr message = codec.getMessage(&buf);
    if(message->create_room == ROOM::C_ROOM_SUCCEED)
    {
        return true;
    }
    return false;
}

bool isEnterRoomSucceed(const int &conn,const ProtobufCodec &codec)
{
    netlib::Buffer buf;
    int ret = read(conn,buf.getWritePeek(),buf.writeableSize());
    assert(ret >= 0);
    MessagePtr message = codec.getMessage(&buf);
    if(message->enter_room == ROOM::E_ROOM_SUCCEED)
    {
        return true;
    }
    return false;
}



