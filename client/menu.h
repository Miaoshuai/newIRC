/*======================================================
    > File Name: menu.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月01日 星期二 23时39分27秒
 =======================================================*/
#pragma once

#include <iostream>
#include <string>

#include <stdio.h>

enum BUTTON
{
    LOGIN = 1,
    REGISTER,
    REGISTER_ROOM,
    ENTER_ROOM,
    QUIT
};

int menu(void)
{
    printf("\t\t\t用户主界面\n\n");
    printf("\t\t1.登陆\n");
    printf("\t\t2.注册\n");
    printf("\t\t3.注册房间\n");
    printf("\t\t4.进入房间\n");
    printf("\t\t5.退出\n");

    int button;
    std::cin>>button;
    return button;
}


