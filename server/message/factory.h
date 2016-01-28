/*======================================================
    > File Name: factory.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月04日 星期一 13时28分13秒
=======================================================*/
/*自动注册消息的消息工厂*/

#pragma once

#include <map>
#include <string>
#include <functional>
#include <memory>
#include "message.h"

class Factory
{
    public:
        template<typename T>
        struct Register //用于将特定构造函数的可调用对象插入map的注册类
        {
            Register(const std::string &key)
            {
                Factory::get().map_.emplace(key,[]{return new T();});//lambda表达式作为可调用对象       
            }
            template<typename... Args>//构造函数为有参数时
            Register(const std::string &key,Args... args)
            {
                Factory::get().map_.emplace(key,[&]{return new T(args...);});
            }
        };

        static Message *produce(const std::string &key)//生产具体的对象
        {
            if(map_.find(key) == map_.end())
            {
                throw std::invalid_argument("the message key is not exist!");
            }
            return map_[key](); //注意lambda在这里执行
        }

        //用智能指针来管理裸指针
        static std::unique_ptr<Message> produce_unique(const std::string &key)
        {
            return std::unique_ptr<Message>(produce(key));
        }

        static std::shared_ptr<Message> produce_shared(const std::string &key)
        {
            return std::shared_ptr<Message>(produce(key));
        }
    private:
        Factory(){};
        Factory(const Factory&) = delete;
        Factory(Factory &&) = delete;

        static Factory &get()//每次返回静态局部变量多额引用可轻松实现类的单例模式
        {
            static Factory instance;
            return instance;
        }
        static std::map<std::string,std::function<Message *(void)>> map_;   //保存type和可调用对象的map
};

std::map<std::string,std::function<Message *(void)>> Factory::map_;

#define REGISTER_MESSAGE_VNAME(T) reg_msg_##T##_
#define REGISTER_MESSAGE(T,key, ...) static Factory::Register<T> REGISTER_MESSAGE_VNAME(T)(key,##__VA_ARGS__)

