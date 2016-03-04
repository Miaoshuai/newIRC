/*======================================================
    > File Name: register.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月04日 星期五 08时40分51秒
 =======================================================*/
#pragma once

#include "message.pb.h"
#include <iostream>
#include "statusCode.h"

//获得注册消息
Register getRegister(void)
{
    std::cout<<"请输入注册名:"<<std::endl;
    std::string registerName;
    std::cin>>registerName;

    std::cout<<"请输入密码:"<<std::endl;
    std::string password1;
    std::cin>>password1;

    std::cout<<"请再次输入密码:"<<std::endl;
    std::string password2;
    std::cin>>password2;

    //设置注册消息
    Register message;
    message.set_user_name(registerName);
    message.set_password1(password1);
    message.set_password2(password2);

    return message;   
}

//发送注册信息
int sendRegisterMessage(const ProtobufCodec &codec,const int &conn,const Register &message)
{
    netlib::Buffer buf;
    codec.fillEmptyBuffer(&buf,message);
    
    int ret = send(conn,buf.getReadPeek(),buf.readableSize(),0);
    return ret;   
} 

//判断是否注册成功
bool isRegisterSucceed(const int conn,const ProtobufCodec &codec)
{
    netlib::Buffer buf;
    int ret = read(conn,buf.getWritePeek(),buf.writeableSize());
    assert(ret >= 0);
    MessagePtr message = codec.getMessage(&buf);
    if(message->register == REGISTER::REGISTER_SUCCEED)
    {
        return true;
    }
    return false;
}


