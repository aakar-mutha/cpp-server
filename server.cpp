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
    std::istringstream requestStream(buffer);

    // Create an HTTPServerRequestImpl object

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

    if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET)
    {
        std::string path = "";
        path.append(request.getURI());
        response = cppServer::get::handle(path, contents);
    }
}

void cppServer::server::respondToRrequest()
{
    // if (status == EXIT_SUCCESS)
    // {
    //     std::string toWrite = "HTTP/1.1 " + std::to_string(Poco::Net::HTTPResponse::HTTP_OK) + "\n";
    //     toWrite += "Content-Type: text/html\n";
    //     toWrite += "Content-Length: " + std::to_string(strlen(contents)) + "\n\n";
    //     toWrite.append(contents);
    //     cout << endl
    //          << toWrite << endl;

    //     write(newSocket, toWrite.c_str(), toWrite.size());
    // }
    // else
    // {
        
    //     std::string toWrite = "HTTP/1.1 " + std::to_string(Poco::Net::HTTPResponse::HTTP_NOT_FOUND) + "\n";
    //     toWrite += "Content-Type: text/html\n";
    //     toWrite += "Content-Length: " + std::to_string(strlen(msg)) + "\n\n";
    //     toWrite.append(msg);
    //     write(newSocket, &toWrite, toWrite.size());
    //     cout << endl
    //          << toWrite << endl;
    //     // session.receiveResponse(response);

    //     write(newSocket, toWrite.c_str(), toWrite.size());
    // }

    // write(newSocket, hello, strlen(hello));
    write(newSocket, response.c_str(), response.size());
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