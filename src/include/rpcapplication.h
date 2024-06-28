#pragma once

//mprpc基础类，进行初始化
class RpcApplication
{
public:
    static void Init(int argc, char **argv);
    static RpcApplication& GetInstance();
private:
    RpcApplication() {}
    RpcApplication(const RpcApplication&) = delete;
    RpcApplication(RpcApplication&&) = delete;
    RpcApplication& operator= (const RpcApplication&) = delete;
    RpcApplication& operator= (RpcApplication&&) = delete;
};