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

typedef std::shared_ptr<google::protobuf::Message> MessagePtr;

class ProtobufCodec
{
    public:
        typedef std::function<void(netlib::connectionPtr &,MessagePtr &)> ProtobufMessageCallback;
        ProtobufCodec(ProtobufMessageCallback messageCallback)
            :messageCallback_(messageCallback)
        {
    
        }
    
        //处理消息
        void onMessage(netlib::connectionPtr conn,netlib::Buffer *buf);
        MessagePtr getMessage(netlib::Buffer *buf);
        //发送数据
        void send(netlib::connectionPtr &conn,google::protobuf::Message &message)
        {
            netlib::Buffer buf;
            fillEmptyBuffer(&buf,message);
            conn->send();
        }

        //填充buffer
        static void fillEmptyBuffer(netlib::Buffer *buf,const google::protobuf::Message &message);

        //生成对应消息类型的消息指针
        static google::protobuf::Message *createMessage(const std::string &type_name);

        //解析消息
        static MessagePtr parse(char *buf,int len);
    private:
        ProtobufMessageCallback messageCallback_;
        const static int kHeaderLen = sizeof(int32_t);
        const static int kMinMessageLen = 2*kHeaderLen + 2;
        const static int kMaxMessageLen = 64*1024*1024;
};


