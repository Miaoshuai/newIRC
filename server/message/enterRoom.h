/*======================================================
    > File Name: enterRoom.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月16日 星期三 15时16分44秒
 =======================================================*/
#pragma once

#include "message.h"
#include <string>
#include <iostream>
#include <stdio.h>

//该房间是否在线
bool isRoomOnline(MessageType::RoomMap &rooms,MessageType::EnterRoomPtr &message)
{
    auto it = rooms.find(message->room_name());
    if(it != rooms.end())
    {
        return true;
    }
    return false;
}

//进入房间
bool enterRoom(MessageType::RoomMap rooms,netlib::connectionPtr conn,MessageType::EnterRoomPtr message,Sql sql)
{
    if(!sql.operate("select roomName from Room where room = "+message->room_name()+""))
    {
        return false;
    }
    else
    {
        if(!isRoomOnline(rooms,message))
        {
            //向RoomMap中插入新房间
            MessageType::ConnectionsClass connections;
            rooms.insert(std::pair<std::string,MessageType::ConnectionsClass>(message->room_name(),connections));
        }
        MessageType::ConnectionsClass &connections = rooms[message->room_name()];
        std::lock_guard<std::mutex> guard(*(connections.mutex_));
        //判断该队列是否有读者
        if(!connections.connections_.unique())
        {
            connections.connections_.reset(new MessageType::ConnectionList(*(connections.connections_)));
        }
        connections.connections_->push_back(conn);
    }
    return true;
}
