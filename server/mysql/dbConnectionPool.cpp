/*======================================================
    > File Name: dbConnectionPool.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月16日 星期三 09时51分56秒
 =======================================================*/
#include "dbConnectionPool.h"
#include <memory>

//初始化创建所有连接
DbConnectionPool::DbConnectionPool(int num)
{
    for(int i = 0; i < num; i++)
    {
        dbConnectionPool_.push_back(std::make_shared<Sql>("127.0.0.1","root","kaiji","IRC"));
    }
}

//释放掉所建的所有连接
DbConnectionPool::~DbConnectionPool(void)
{
}

//获取某个连接
std::shared_ptr<Sql> getConnection(void)
{
    auto connection = dbConnectionPool_.front();
    dbConnectionPool_.pop_front();
    return connection;
}

//回收某个连接
void freeConnection(Sql *sql)
{
    dbConnectionPool_.push_front(std::make_shared<Sql>(sql));
}


