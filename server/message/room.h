/*======================================================
    > File Name: room.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月03日 星期四 00时05分31秒
=======================================================*/
#pragma once

#include "message.h"
#include <string>
#include <mutex>

//检查room消息是注册新房间还是进入此房间
bool checkRoomMessage(MessageType::RoomPtr message)
{
    std::string what(message->what());
    if(what == "new")
    {
        return true;
    }
    else
    {
        return false;
    }   
}

//注册新房间
bool registerRoom(MessageType::RoomPtr message,Sql sql)
{
    if(!sql.operate("select roomName from Room where room = "+message->room_name()+""))
    {
        return false;
    }
    else
    {
        if(!sql.operate("insert into Room values("+message->room_name()+")"))
        {
            return false;
        }
    }
    return true;
}

bool isRoomExist(const MessageType::RoomMap &rooms,MessageType::RoomPtr & message)
{
    auto it = rooms.find(message->room_name());
    if(it != rooms.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//进入房间
bool enterRoom(MessageType::RoomMap rooms,netlib::connectionPtr conn,MessageType::RoomPtr message,Sql sql)
{
    if(!sql.operate("select roomName from Room where room = "+message->room_name()+""))
    {
        return false;
    }
    else
    {
        if(!isRoomExist(rooms,message))
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
