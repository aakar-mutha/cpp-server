//
// Created by marketingharp on 5/22/24.
//

#ifndef SERVER_H
#define SERVER_H

#include "networking/cppServerLib-networking.h"
namespace cppServer {
    class server : public createServer
    {
    private:
        /* data */
        char buffer[30000] = {0};
        int newSocket;
        void acceptRequest();
        void handleRequest();
        void respondToRrequest();
    public:
        server();
        void launch();
    };
    
    
}

#endif //SERVER_H
