/*======================================================
    > File Name: codec.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月29日 星期五 16时34分40秒
 =======================================================*/
/*编解码器*/

#pragma once

#include "buffer.h"
#include "connection.h"

#include <functional>
#include <memory>
#include <string>

#include <google/protobuf/message.h>

typedef std::unique_ptr<google::protobuf::Message> MessagePtr;

class ProtobufCodec
{
    public:
        typedef std::function<void(const netlib::connectionPtr &,const MessagePtr &)> ProtobufMessageCallback;
        explicit ProtobufCodec(const ProtobufMessageCallback &messageCallback)
            :messageCallback_(messageCallback),
        {
    
        }
    
        //处理消息
        void onMessage(const netlib::connectionPtr &,netlib::Buffer *buf);
        //发送数据
        void send(const netlib::connectionPtr &conn,const google::protobuf::Message &message)
        {
            netlib::Buffer buf;
            fillEmptyBuffer(&buf,message);
            conn->send(&buf);
        }

        //填充buffer
        static void fillEmptyBuffer(netlib::Buffer *buf,const google::protobuf::Message &message);

        //生成对应消息类型的消息指针
        static google::protobuf::Message *createMessage(const std::string &type_name);

        //解析消息
        static MessagePtr parse(const char *buf,int len);
    private:
        ProtobufMessageCallback messageCallback_;
        const static int kHeaderLen = sizeof(int32_t);
        const static int kMinMessageLen = 2*kHeaderLen;
        const static int kMaxMessageLen = 64*1024*1024;
};


