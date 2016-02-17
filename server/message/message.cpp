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
#include "statusCode.h"
#include <iostream>
#include <assert.h>

void MessageType::onLogin(netlib::connectionPtr conn,LoginPtr message)
{
    
}

void MessageType::onRegister(netlib::connectionPtr conn,RegisterPtr message)
{
    //判断该用户名是否已经存在
    Status status;   
    if(isUserExist(message,sql_) && !checkPassword(message))
    {
        status.set_register_(REGISTER::FAIL);                       
    }
    else
    {
        status.set_register_(REGISTER::SUCCEED);
        //将新用户添加到user表中
        assert(registerUser(message,sql_));
    }
    codec_.fillEmptyBuffer(&conn->outputBuffer_,status);
    conn->send();    
}
