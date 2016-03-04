/*======================================================
    > File Name: client.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月01日 星期二 23时38分34秒
 =======================================================*/
#include "processOptions.h"
#include "connectServer.h"
#include "menu.h"
#include <string>
#include <stdlib.h>

class Client
{
    public:
        Client(std::string ip,int port)
            :processOption_(connectServer(ip,port)),
             flag_(0)
        {
               
        }

        void start(void)
        {
            while(true)
            {
                int button = menu();
                selectOptions(button);
                if(1 == flag_)break;   
            }
        }

    private:
        //根据用户选择调用具体的消息处理函数
        void selectOptions(int choice)
        {
            switch(choice)
            {
                case:LOGIN
                   processOption_.handleLogin();break;
                case:REGISTER:
                   processOption_.handleRegister();break;
                case:REGISTER_ROOM:
                   processOption_.handleRegisterRoom();break;
                case:ENTER_ROOM:
                   processOption_.handleEnterRoom();break;
                case:QUIT
                   flag_ = 1;break;
                default:
                   std::cout<<"您的输入有误"<<std::endl;
            }
        }

        ProcessOptions processOption_;  //负责消息处理的类
        int flag_
};

int main(int argc,char **argv)
{
    Client client(argv[1],atoi(argv[2]));
    Client.start();
}
