/*======================================================
    > File Name: login.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年02月18日 星期四 22时47分49秒
 =======================================================*/
#pragma once

#include <mutex>
#include "message.h"


//检查用户名和密码
bool checkUserAndPassword(MessageType::LoginPtr message,Sql sql)
{
    if(!sql.operate("select userName from User where userName = "+message->user_name()+""))
    {
        return false;
    }
    else
    {
        if(!sql.operate("select password from User where password = "+message->password()+""))
        {
            return false;
        }
    }
    return true;    
}





