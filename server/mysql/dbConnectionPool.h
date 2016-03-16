/*======================================================
    > File Name: dbConnectionPool.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月16日 星期三 09时26分55秒
 =======================================================*/
#pragma once

#include "mysql.h"
#include <list>
#include <memory>

class DbConnectionPool
{
    public:
        //初始化创建所有连接
        DbConnectionPool(int num);
        //关闭所有连接
        ~DbConnectionPool();
        //获取某个连接
        std::shared_ptr<Sql> getConnection(void);
        //回收某个连接
        void freeConnection(Sql *);
    private:
        std::list<std::shared_ptr<Sql>> dbConnectionPool_; //连接池队列       
};

