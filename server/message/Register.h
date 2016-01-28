/*======================================================
    > File Name: Register.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月28日 星期四 16时02分34秒
 =======================================================*/
/*注册类的实现*/

#pragma once

#include "message.h"
#include "factory.h"

class Register : public Message
{
    public:
        Register()
        {
            handleMessage();
        }
        ~Register(){}

        void handleMessage()override
        {
        
        }
};

//注册到factory的map中去
REGISTER_MESSAGE(Register,"Register");
