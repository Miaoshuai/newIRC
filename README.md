###Linux下可订阅聊天室

####主要功能
	用户可登陆可登陆账号订阅自己感兴趣的聊天室尽情的与志同道合的人畅所欲聊

####服务器主要流程
>服务器采用多线程模型，其中一个线程只负责accept新的socket并通过eventfd将新连接的套接字描述符分发给各个工作线程(每个工作线程搭载一个epoll运用了one loop per thread的思想)。当工作线程中有数据到来时，首先会被读到该连接对应的buffer中，待buffer中数据达到一条完整的数据时，将其读出，并使用protobuf协议对二进制数据进行反序列化。之后消息分发器会根据该消息类型来调用具体的消息处理回调
####使用到的一些技术
(1)通过创建Connection的连接池，从而减少了频繁创建和关闭Connection对象
(2)通过创建数据库连接池，重复循环利用数据库连接，提升服务器性能
(3)利用shared_ptr的引用计数，实现类似读写锁的功能，显著减少锁竞争
(4)对数据库非主键并频繁查询的列创建索引，查询速度以数量级提升
(5)创建一个看门狗守护进程，当其子进程(主服务器)挂掉，则其wait返回，并立刻重启服务器进程
(6)异步日志不仅保证了服务器对日志的需求，也不占用过多的服务器资源
(7)设置应用层的ack从而保证用户消息准确送给用户

