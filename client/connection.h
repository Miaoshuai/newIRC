/*======================================================
    > File Name: connection.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2015年12月21日 星期一 17时06分48秒
 =======================================================*/
#ifndef CONNECTION_H_
#define CONNECTION_H_
#include "buffer.h"
#include "epoll.h"

#include <assert.h>
#include <stdio.h>
#include <memory>
#include <string>


namespace netlib
{
    class Connection
    {
        public:
            int fd_;    //标示此连接的描述符
            std::string ConnectionName_;//连接的名字
            Buffer inputBuffer_;    //输入buffer
            Buffer outputBuffer_;   //输出buffer
            std::shared_ptr<Epoll> epoll_;          //该连接所运行的epoll
        public:
            Connection(int fd,std::shared_ptr<Epoll> epoll)
                :fd_(fd),
                epoll_(epoll)
            {
        
            }
            ~Connection()
            {
            
            }
            //发送数据
            int send(void)
            {
                //可写的字节数
                int ableWrites = outputBuffer_.readableSize();
                assert(ableWrites >= 0);
                int writeBytes = outputBuffer_.writeToFd(fd_);
                //已写的字节数小于buffer中可写的字节数，则说明内核写缓冲已满
                if(writeBytes < 0)
                {
                    printf("发送数据出错\n");
                }
                else if(writeBytes < ableWrites)
                {
                    registerWriteEvent();                    
                }
                else if(writeBytes == ableWrites)
                {
                    deleteWriteEvent();
                }
                return writeBytes;
            }
            //注册写事件
            void registerWriteEvent(void)
            {
                int events = EPOLLIN | EPOLLOUT;
                epoll_->modFd(fd_,events);                      
            }

            //删除写事件
            void deleteWriteEvent(void)
            {
                int events = EPOLLIN;
                epoll_->modFd(fd_,events);
            }
    };
    typedef std::shared_ptr<Connection> connectionPtr;
}
#endif
