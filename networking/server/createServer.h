//
// Created by marketingharp on 5/24/24.
//

#ifndef CREATESERVER_H
#define CREATESERVER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../cppServerLib-networking.h"

namespace cppServer{
    class createServer{
        private:
            listeningSocket * socket;

        public:
            createServer(int domain, int service, int protocol, int port, u_long interface, int bklg);
            virtual void acceptRequest() = 0;
            virtual void handleRequest() = 0; 
            virtual void respondToRrequest() = 0;
            virtual void launch() = 0;
            listeningSocket * getSocket(); 
    };
}
#endif //CREATESERVER_H
