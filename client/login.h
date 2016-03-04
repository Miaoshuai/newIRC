/*======================================================
    > File Name: login.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月03日 星期四 23时50分47秒
 =======================================================*/
#pragma once

#include <string>
#include <iostream>
#include "message.pb.h"
#include "buffer.h"
#include "processOptions.h"
#include "statusCode.h"
#include <assert.h>

//获得登陆消息
Login getLoginMessage(void)
{
    std::cout<<"请输入登录名:"<<std::endl;
    std::string userName;
    std::cin>>userName;
    
    std::cout<<"请输入密码:"<<std::endl;
    std::string password;
    std::cin>>password;
    
    //设置登陆消息
    Login message;
    message.set_user_name(userName);
    message.set_password(password); 
    
    return message;
}

//发送登陆消息
int sendLoginMessage(const ProtobufCodec &codec,const int &conn,const Login &message)
{
    netlib::Buffer buf;
    codec.fillEmptyBuffer(&buf,message);
    
    int ret = send(conn,buf.getReadPeek(),buf.readableSize(),0);
    return ret; 
}

//判断是否登陆成功
bool isLoginSucceed(const int &conn,const ProtobufCodec &codec)
{
    netlib::Buffer buf;
    int ret = read(conn,buf.getWritePeek(),buf.writeableSize());
    assert(ret >= 0);
    MessagePtr message = codec.getMessage(&buf);
    if(message->login == LOGIN::LOGIN_SUCCEED)
    {
        return true;
    }
    return false;
}


