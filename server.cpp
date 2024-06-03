//
// Created by marketingharp on 5/22/24.
//

#include "server.h"

cppServer::server::server() : createServer(AF_INET, SOCK_STREAM, 0, 3000, INADDR_ANY, 10)
{
    launch();
}

void cppServer::server::acceptRequest()
{
    struct sockaddr_in address = getSocket()->getAddress();
    int addressLen = sizeof(address);
    newSocket = accept(getSocket()->getSock(), (struct sockaddr *)&address, (socklen_t *)&addressLen);

    read(newSocket, buffer, 30000);
}

void cppServer::server::handleRequest()
{
    // cout << buffer << endl;   
    std::istringstream requestStream(buffer);

    // Create an HTTPServerRequestImpl object
    Poco::Net::HTTPRequest request;

    try
    {
        request.read(requestStream);
    }
    catch (const Poco::Exception &ex)
    {
        std::cerr << "Failed to parse HTTP request: " << ex.displayText() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Now you can access request attributes
    std::cout << "Method: " << request.getMethod() << std::endl;
    std::cout << "URI: " << request.getURI() << std::endl;
    std::cout << "HTTP Version: " << request.getVersion() << std::endl;
    std::cout << "Host: " << request.getHost() << std::endl;
    std::cout << "User-Agent: " << request.get("User-Agent") << std::endl;
    std::cout << "Content-Length: " << request.getContentLength() << std::endl;

}

void cppServer::server::respondToRrequest()
{
    char *hello = "<p>Hello from the server</p>";
    write(newSocket, hello, strlen(hello));
    close(newSocket);
}

// void cppServer::server::stopHandler(int sig){
//     signal(sig, SIG_IGN);
//     cout << "The server shut down gracefully!!";
// }

void cppServer::server::launch()
{
    // signal(SIGINT, cppServer::server::stopHandler);
    while (true)
    {
        cout << "========== WAITING ==========" << endl;
        acceptRequest();
        handleRequest();
        respondToRrequest();
        cout << "========== DONE ==========" << endl;
    }
}