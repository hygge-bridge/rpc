#include "rpcapplication.h"
#include <iostream>
#include <unistd.h>
#include <string>

void ShowArgsHelp()
{
    std::cout << "format: command -i <configfile>" << std::endl;
}

void RpcApplication::Init(int argc, char **argv)
{
    if (argc < 2)
    {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }
    int ch = 0;
    std::string configFile;
    while ((ch = getopt(argc, argv, "i:")) != -1)
    {
        switch(ch)
        {
        case 'i':
            configFile = optarg;
            break;
        case '?':
            std::cout << "invalid args" << std::endl;
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }
}

RpcApplication& RpcApplication::GetInstance()
{
    static RpcApplication app;
    return app;
}