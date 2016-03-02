/*======================================================
    > File Name: thread_pool_test.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2015年12月27日 星期日 14时36分35秒
 =======================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "thread_pool.h"
#include <unistd.h>

void fun(std::string s)
{
    std::cout<<s<<std::endl;
}

int main(int argc,char **argv)
{
  netlib::ThreadPool pool(10);
  pool.start();
  while(1)
  {
    pool.append(std::bind(fun,std::string("hello")));
  }  
  return 0;
}
