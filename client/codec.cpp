/*======================================================
    > File Name: codec.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月29日 星期五 23时34分09秒
 =======================================================*/
#include "codec.h"
#include "buffer.h"
#include "endian.h"

#include <assert.h>
#include <stdio.h>

#include <google/protobuf/descriptor.h>

void ProtobufCodec::fillEmptyBuffer(netlib::Buffer *buf,const google::protobuf::Message &message)
{
    assert(buf->readableSize() == 0);

    const std::string &typeName = message.GetTypeName();
    //类型名字长度包含'/0'
    int32_t nameLen = static_cast<int32_t>(typeName.size() + 1);

    //消息长度
    int byte_size = message.ByteSize();
    buf->makeSureEnough(byte_size);
    //总长度
    int32_t len = nameLen + kHeaderLen + byte_size;
    buf->appendInt32(len);
    //将名字长度和名字加入到buffer中去
    buf->appendInt32(nameLen);
    buf->append(typeName.c_str(),nameLen);
    
    uint8_t *start = reinterpret_cast<uint8_t *>(buf->getWritePeek());
    //将消息从start位置开始序列化
    uint8_t *end = message.SerializeWithCachedSizesToArray(start);
    buf->moveWriteIndex(byte_size);
    assert(end - start == byte_size);

}

void ProtobufCodec::onMessage(netlib::connectionPtr conn,netlib::Buffer *buf)
{
    while(buf->readableSize() >= (kMinMessageLen))  //类型为空，名字只占一个字母还有'/0'
    {
        printf("readableSize = %d\n",buf->readableSize());
        int len = buf->peekInt32();
        buf->moveReadIndex(sizeof(int32_t));

        assert(len < kMaxMessageLen && len >= kMinMessageLen);
        
        if(buf->readableSize() >= static_cast<size_t>(len))
        {
            MessagePtr message = parse(buf->getReadPeek(),len);
            //完整消息时才触发回调
            messageCallback_(conn,message);
            buf->moveReadIndex(len);
            printf("111\n");
        }
        printf("222\n");
    }
}

MessagePtr getMessage(netlib::Buffer *buf)
{
    int len = buf->peekInt32();
    buf->moveReadIndex(sizeof(int32_t));

    assert(len < kMaxMessageLen && len >= kMinMessageLen);

    if(buf->readableSize() >= static_cast<size_t>(len))
    {
        MessagePtr message = parse(buf->getReadPeek(),len);
        return message;
    }
    return NULL;
}

google::protobuf::Message *ProtobufCodec::createMessage(const std::string &typeName)
{
    google::protobuf::Message *message = NULL;
    const google::protobuf::Descriptor *descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(typeName);
    if(descriptor)
    {
        const google::protobuf::Message *prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
        if(prototype)
        {
            message = prototype->New();
        }
    }
    return message;
}

int32_t asInt32(const char *buf)
{
    int32_t be32 = 0;
    memcpy(&be32,buf,sizeof(be32));
    hello();
    return networkToHost32(be32);
}


MessagePtr ProtobufCodec::parse(char *buf,int len)
{
    MessagePtr message;
    int32_t nameLen = asInt32(buf);
    if(nameLen >=2 && nameLen <= len - kHeaderLen)
    {
        std::string typeName(buf + kHeaderLen,buf + kHeaderLen + nameLen -1);
        //创建消息对象
        message.reset(createMessage(typeName));
        if(message)
        {
            const char *data = buf + kHeaderLen + nameLen;
            int32_t dataLen = len - nameLen - 2*kHeaderLen;
            //从Buffer中获取完整的消息格式
            if(message->ParseFromArray(data,dataLen))
            {
                printf("解析消息成功\n");
            }
        }
    }
    return message;   
}
