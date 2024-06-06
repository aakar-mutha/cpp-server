//
// Created by marketingharp on 5/22/24.
//

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <stdio.h>
// #include <signal.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <cstdio>
#include "networking/cppServerLib-networking.h"
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequestImpl.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/File.h>
#include <Poco/FileStream.h>
#include <Poco/Net/HTTPClientSession.h>


using namespace std;
// using namespace httpparser;

namespace cppServer {
    class server : public createServer
    {
    private:
        /* data */
        char buffer[30000] = {0};
        int newSocket;
        char contents[30000] = {0};
        int status;

        Poco::Net::HTTPRequest request;
        string response;
        void acceptRequest();
        void handleRequest();
        void respondToRrequest();
        // static void stopHandler(int sig);

    public:
        server();
        void launch();
    };    
}

#endif //SERVER_H
