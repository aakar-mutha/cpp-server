//
// Created by marketingharp on 5/28/24.
//

#ifndef TESTSERVER_H
#define TESTSERVER_H


#include "createServer.h"

namespace cppServer {
    class testServer : public createServer
    {
    private:
        /* data */
        char buffer[30000] = {0};
        int newSocket;
        void acceptRequest();
        void handleRequest();
        void respondToRrequest();
    public:
        testServer();
        void launch();
    };
    
    
}
#endif //TESTSERVER_H
