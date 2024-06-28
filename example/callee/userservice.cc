#include <iostream>
#include <string>
#include "user.pb.h"
#include "rpcapplication.h"
#include "rpcprovider.h"

// 本地用户服务
class UserService : public hygge::UserServiceRpc
{
public:
    // 登录
    bool Login(std::string name, std::string pwd)
    {
        std::cout << "Login service:" << std::endl;
        std::cout << "name:" << name << " pwd:" << pwd << std::endl;
        return true;
    }

    // 重写Login虚函数
   void Login(::google::protobuf::RpcController* controller,
                       const ::hygge::LoginRequest* request,
                       ::hygge::LoginResponse* response,
                       ::google::protobuf::Closure* done)
    {
        std::string name = request->name();
        std::string pwd = request->pwd();

        bool loginResult = Login(name, pwd);

        hygge::ResultCode *res = response->mutable_result();
        res->set_errcode(0);
        res->set_errmsg("");
        response->set_success(loginResult);

        done->Run();
    }
};

int main(int argc, char **argv)
{
    RpcApplication::Init(argc, argv);

    RpcProvider provider;
    provider.NotifyService(new UserService);

    provider.Run();
    return 0;
}