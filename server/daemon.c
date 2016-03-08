/*======================================================
    > File Name: daemon.c
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月08日 星期二 19时38分42秒
 =======================================================*/
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <time.h>
#include <syslog.h>
#include <assert.h>
#include <sys/wait.h>
#include <stdlib.h>

int init_daemon(char **argv,char **env)
{
    int pid;
    int i;
    
    //忽略终端的I/O信号
    signal(SIGTTOU,SIG_IGN);
    signal(SIGTTIN,SIG_IGN);
    signal(SIGTSTP,SIG_IGN);
    signal(SIGHUP,SIG_IGN);
    
    pid = fork();
    if(pid > 0)
    {   
        exit(0);
    }
    else if(-1 == pid)
    {
        return -1;
    }

    //将自己脱离init并提升为会话组长
    setsid();
    pid = fork();
    if(pid > 0)
    {
        
        exit(0);
    }
    else if(-1 == pid)
    {
        return -1;
    }
    
    //关闭所有从父进程那继承来的套接字描述符
    for(i=0; i< NOFILE; close(i++));

    //改变文件目录使得进程不与任何文件系统关联
    chdir("/");

    //将文件屏蔽字设为０
    umask(0);
    pid = fork();
    if(pid == 0)
    {
        int n = execve("/home/newIRC/server/server",argv,env);
        if(-1 == n)
        {
            printf("fail\n");
        }
    }
    else if(pid > 0)
    {
        //父进程循环监控子进程是否退出，若退出则调用fork重新拉起子进程
        while(1)
        {
            wait(NULL);
            pid = fork();
            if(pid == 0)
            {
                int n = execve("/home/newIRC/server/server",argv,env);
            }
        }      
    }


    return 0;
}

int main(int argc,char **argv,char **env)
{
    init_daemon(argv,env);
    return 0;
}


