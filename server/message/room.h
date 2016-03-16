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
#include <stdio.h>
#include "timestamp.h"
#include <iostream>

//检查room消息是注册新房间还是进入此房间
bool checkRoomMessage(MessageType::RoomPtr &message)
{
    printf("111\n");
    std::string what(message->what());
    if(what == "create")
    {
        return true;
    }
    else
    {
        return false;
    }   
}

//注册新房间
bool registerRoom(MessageType::RoomPtr &message,Sql &sql,netlib::connectionPtr &conn)
{
    //printf("222\n");
    /*char temp1[200];
    snprintf(temp1,sizeof(temp1),"select roomName from Room where roomName = '%s'",message->room_name().c_str());
    if(!sql.operate(temp1))
    {
        return false;
    }*/
    
    printf("333\n");
    std::cout<<"roomName:"<<message->room_name()<<std::endl;
    char temp2[200];
    netlib::Timestamp stamp;
    snprintf(temp2,sizeof(temp2),"insert into Room values('%s','%s','%s')",conn->ConnectionName_.c_str(),message->room_name().c_str(),stamp.toStringTime());
    if(!sql.operate(temp2))
    {
        return false;
    }
    
    printf("444\n");
    return true;
}

//该房间是否存在于数据库
bool isRoomExist(MessageType::RoomPtr &message,Sql &sql)
{
    char temp[200];
    std::cout<<message->room_name()<<std::endl;
    snprintf(temp,sizeof(temp),"select roomName from Room where roomName = '%s'",message->room_name().c_str());
    if(!sql.operate(temp))
    {
        printf("555\n");
        return true;
    }
    else
    {
        printf("666\n");
        return false;
    }
}

//该房间是否在线
bool isRoomOnline(MessageType::RoomMap &rooms,MessageType::RoomPtr &message)
{
    auto it = rooms.find(message->room_name());
    if(it != rooms.end())
    {
        return true;
    }
    return false;
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
