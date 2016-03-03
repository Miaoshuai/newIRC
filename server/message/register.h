/*======================================================
    > File Name: register.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年02月17日 星期三 11时23分55秒
 =======================================================*/
#pragma once

#include <mutex>
#include "message.h"

//检查俩次密码是否相同
bool checkPassword(MessageType::RegisterPtr &message)
{
    if(message->password1() == message->password2())
    {
        return true;
    }
    else
    {
        return false;
    }
}


//判断该用户名是否已经存在
bool isUserExist(MessageType::RegisterPtr &message,Sql sql)
{
    if(sql.operate("select userName from User where userName = "+message->user_name()+""))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//注册新用户到user表
bool registerUser(MessageType::RegisterPtr &message,Sql &sql)
{
    sql.operate("insert into user values("+message->user_name()+","+message->password1()+")");
    return true;   
}

