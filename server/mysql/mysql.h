/*************************************************************************
    > File Name: mysql.h
    > Author: MiaoShuai
    > Mail: 945970809@qq.com 
    > Created Time: 2015年09月09日 星期三 16时16分35秒
 ************************************************************************/
#pragma once

#include<string>
#include<mysql/mysql.h>


class Sql
{
	public:
		//构造函数用来初始化mysql和连接数据库
		Sql(std::string iP,std::string name,std::string passwd,std::string database);
		//析构函数用来做数据库的善后处理
		~Sql();
		//对数据库进行sql操作
		bool operate(const std::string &operation);
        //获取行
        MYSQL_ROW getRow(void);
        //获取列数
        int getColNum(void);
		//打印获得的操作结果
		void print_result(void);

	private:
		std::string server_ip;		//数据库地址
		std::string user_name;		//用户名
		std::string password;		//用户密码
		std::string database_name;	//数据库名
	private:
		MYSQL		*mysql_conn;
		MYSQL_RES	*mysql_res;
		MYSQL_ROW	mysql_row;
};

