//
// Created by marketingharp on 5/22/24.
//

#include "server.h"
using namespace std;

cppServer::server::server() : createServer(AF_INET, SOCK_STREAM, 0, 3000, INADDR_ANY, 10){
    launch();
}

void cppServer::server::acceptRequest(){
    struct sockaddr_in address = getSocket()->getAddress();
    int addressLen = sizeof(address);
    newSocket = accept(getSocket()->getSock(), (struct sockaddr *) &address , (socklen_t *) &addressLen);

    read(newSocket, buffer, 30000);
}

void cppServer::server::handleRequest(){
    cout << buffer << endl;
}

void cppServer::server::respondToRrequest(){
    char *hello = "<p>Hello from the server</p>";
    write(newSocket, hello, strlen(hello));
    close(newSocket);
}

void cppServer::server::launch(){
    while (true)
    {
        cout << "========== WAITING ==========" << endl;
        acceptRequest();
        handleRequest();
        respondToRrequest();
        cout << "========== DONE ==========" << endl;
    }
    
}