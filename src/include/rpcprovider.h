#pragma once
#include "google/protobuf/service.h"

// 提供rpc方法服务
class RpcProvider
{
public:
    // 发布服务
    void NotifyService(google::protobuf::Service *service);
    // 启动rpc服务，提供远程网络调用
    void Run();
};