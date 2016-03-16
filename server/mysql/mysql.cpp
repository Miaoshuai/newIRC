/*======================================================
    > File Name: mysql.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2015年12月10日 星期四 18时33分20秒
 =======================================================*/
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include "mysql.h"
#include <stdio.h>

//构造函数
Sql::Sql(const std::string ip,const std::string name,const std::string passwd,const std::string database)
{
    printf("000\n");
    //初始化自定义变量
    server_ip = ip;
    user_name = name;
    password = passwd;
    database_name = database;
    
    //初始化mysql
    mysql_conn = mysql_init(NULL);

    //连接mysql
    if(!mysql_real_connect(mysql_conn,server_ip.c_str(),user_name.c_str(),password.c_str(),database_name.c_str(),0,NULL,0))
    {
        std::cout<<"mysql连接失败"<<std::endl;
        exit(1);
    }
    else
    {
        std::cout<<"mysql连接成功"<<std::endl;
    }
}


//操作函数
bool Sql::operate(const std::string &operation)
{
    if(mysql_query(mysql_conn,operation.c_str()))
    {
        std::cout<<"mysql操作失败"<<std::endl;
        return false;
    }
    

    //将操作结果存储在结果集
    mysql_res = mysql_use_result(mysql_conn);
    mysql_free_result(mysql_res);
    return true;
}

MYSQL_ROW Sql::getRow(void)
{
    return mysql_fetch_row(mysql_res);
}

int Sql::getColNum(void)
{
    return mysql_num_fields(mysql_res);
}

//打印操作结果
void Sql::print_result(void)
{
    //获得每行的字段数
    int num = mysql_num_fields(mysql_res);

    //循环读取所有行
    while((mysql_row = mysql_fetch_row(mysql_res)) != NULL)
    {
        //将每行字段都读出来
        
        for(int i = 0; i < num; i++)
        {
            std::cout<<mysql_row[i]<<"   ";
        }
        std::cout<<std::endl;
    }
}



Sql::~Sql()
{
    //释放存储结果
    mysql_free_result(mysql_res);
    //关闭mysql连接
    mysql_close(mysql_conn);
}
