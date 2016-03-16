/*======================================================
    > File Name: registerRoom.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月16日 星期三 14时46分11秒
 =======================================================*/
#pragma once

#include "message.h"
#include "timestamp.h"
#include <string>
#include <iostream>
#include <stdio.h>

//检查该房间是否存在于数据库中
bool isRoomExist(MessageType::RegisterRoomPtr &message,Sql &sql)
{
    char temp[200];
    std::cout<<message->room_name()<<std::endl;
    snprintf(temp,sizeof(temp),"select roomName from Room where roomName = '%s'",message->room_name().c_str());
    if(sql.operate(temp))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//注册新房间
bool registerRoom(MessageType::RegisterRoomPtr &message,Sql &sql,netlib::connectionPtr &conn)
{
    std::cout<<"roomName:"<<message->room_name()<<std::endl;
    char temp2[200];
    netlib::Timestamp stamp;
    snprintf(temp2,sizeof(temp2),"insert into Room values('%s','%s','%s')",conn->ConnectionName_.c_str(),message->room_name().c_str(),stamp.toStringTime());
    if(!sql.operate(temp2))
    {
        return false;
    }
    return true;
}
