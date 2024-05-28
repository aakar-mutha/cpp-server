//
// Created by marketingharp on 5/24/24.
//

#include "createServer.h"
cppServer::createServer::createServer(int domain, int service, int protocol, int port, u_long interface, int bklg){
    socket = new listeningSocket(domain, service, protocol, port, interface, bklg);
};

cppServer::listeningSocket * cppServer::createServer::getSocket(){
    return socket;
}