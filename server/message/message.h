/*======================================================
    > File Name: message.h
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月28日 星期四 15时58分29秒
 =======================================================*/
/*所有消息的始祖基类*/

#pragma once

class Message
{
    public:
        virtual ~Message()[]

        //由子类实现的消息处理接口
        virtual void handleMessage()
        {
        
        }
};
