/*======================================================
    > File Name: LogIn.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月28日 星期四 16时08分23秒
 =======================================================*/
/*登陆类*/

#pragma once

#include "message.h"
#include "factory.h"

class LogIn : public Message
{
    public:
        LogIn()
        {
            handleMessage();
        }
        ~LogIn(){}

        void handleMessage()override
        {
        
        }
};

//注册到factory的map中去
REGISTER_MESSAGE(LogIn,"LogIn");
