/*======================================================
    > File Name: dispatcher.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月29日 星期五 21时42分45秒
 =======================================================*/
#pragma once

#include "connection.h"

#include <google/protobuf/message.h>

#include <map>
#include <string>
#include <functional>
#include <memory>

typedef std::shared_ptr<google::protobuf::Message> MessagePtr;

class Callback
{
    public:
        virtual ~Callback(){}

        virtual void onMessage(netlib::connectionPtr &,MessagePtr &message)=0;
};

template<typename T>
class CallbackT : public Callback
{
    public:
        typedef std::function<void(netlib::connectionPtr,std::shared_ptr<T>)> ProtobufMessageTCallback;
        CallbackT(ProtobufMessageTCallback &callback)
            :callback_(callback)
        {
        
        }

        void onMessage(netlib::connectionPtr &conn,MessagePtr &message)
        {
            //调用此消息处理函数时自动进行类型转换
            //std::shared_ptr<T> concrete(static_cast<T *>(message.get()));
            std::shared_ptr<T> concrete = std::static_pointer_cast<T>(message);
            assert(concrete != NULL);
            callback_(conn,concrete);
        }

    private:
        ProtobufMessageTCallback callback_;
};


class ProtobufDispatcher
{
    public:
        typedef std::function<void(netlib::connectionPtr &,MessagePtr &message)> ProtobufMessageCallback;

        explicit ProtobufDispatcher(){}

        void onProtobufMessage(netlib::connectionPtr &conn,MessagePtr &message)
        {
            auto it = callbacks_.find(message->GetDescriptor());
            if(it != callbacks_.end())
            {
                it->second->onMessage(conn,message);
            }           
        }

        template<typename T>
        void registerMessageCallback(typename CallbackT<T>::ProtobufMessageTCallback callback)
        {
            std::shared_ptr<CallbackT<T>> pd(new CallbackT<T>(callback));
            callbacks_[T::descriptor()] = pd;           
        }

    private:
        typedef std::map<const google::protobuf::Descriptor *,std::shared_ptr<Callback>> CallbackMap;

        CallbackMap callbacks_;
};
