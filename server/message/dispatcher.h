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

        virtual void onMessage(const netlib::connectionPtr &,const MessagePtr &message);
};

template<typename T>
class CallbackT : public Callback
{
    public:
        typedef std::function<void(const netlib::connectionPtr &,const std::shared_ptr<T> &message)> ProtobufMessageTCallback;
        CallbackT(const ProtobufMessageTCallback &callback)
            :callback_(callback)
        {
        
        }

        virtual void onMessage(const netlib::connectionPtr &conn,const MessagePtr &message)
        {
            std::shared_ptr<T> concrete = static_cast<T>(message);
            assert(concrete != NULL);
            callback_(conn,concrete);
        }

    private:
        ProtobufMessageTCallback callback_;
};


class ProtobufDispatcher
{
    public:
        typedef std::function<void(const netlib::connectionPtr &,const MessagePtr &message)> ProtobufMessageCallback;

        explicit ProtobufDispatcher(){}

        void onProtobufMessage(netlib::connectionPtr &conn,const MessagePtr &message)
        {
            CallbackMap::iterator it = callbacks_.find(message->GetDescriptor());
            if(it != callbacks_.end())
            {
                it->second->onMessage(conn,message);
            }           
        }

        template<typename T>
        void registerMessageCallback(const typename CallbackT<T>::ProtobufMessageTCallback &callback)
        {
            std::shared_ptr<CallbackT<T>> pd(new CallbackT<T>(callback));
            callbacks_[T::descriptor()] = pd;           
        }

    private:
        typedef std::map<google::protobuf::Descriptor *,std::shared_ptr<Callback>> CallbackMap;

        CallbackMap callbacks_;
};
