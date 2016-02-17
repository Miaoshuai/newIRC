/*======================================================
    > File Name: register.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年02月17日 星期三 11时23分55秒
 =======================================================*/
#pragma once

//检查俩次密码是否相同
bool checkPassword(const RegisterPtr & message)
{
    if(message->password1() == message->password2())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断该用户名是否已经存在
bool isUserexist(const RegisterPtr & message,const Sql &sql)
{
    return sql.operate("select userName from user where userName = "+message->user_name+"");      
}
