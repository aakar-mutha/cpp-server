//
// Created by marketingharp on 5/22/24.
//

#include "listeningSocket.h"

cppServer::listeningSocket::listeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg) : bindingSocket(domain, service, protocol, port, interface)
{
    backlog = bklg;
    
    startListening();
    testConnection(listening);
}

void cppServer::listeningSocket::startListening(){
    listening = listen(getSock(), backlog);
    
}