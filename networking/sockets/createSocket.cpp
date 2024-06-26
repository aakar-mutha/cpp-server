/*
Created By : Aakar Mutha 
Date: 05/21/2024
File: createSocket.cpp
*/
#include "createSocket.h"

cppServer::createSocket::createSocket(int domain, int service, int protocol, int port, u_long interface){
    /*
    DOMAIN: AF_INET (IP), AF_INET6 (IPv6), AF_UNIX (local channel, similar to pipes), AF_ISO (ISO protocols), and AF_NS (Xerox Network Systems protocols)
    SERVICE: SOCK_STREAM (virtual circuit service), SOCK_DGRAM (datagram service), SOCK_RAW (direct IP service)
    PROTOCOL: 0: TCP/IP
    */
    
    // Define address structure.
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // Create and test Socket.
    sock = socket(domain, service, protocol);
    testConnection(sock);
}

/* Test if the connection was successful. */
void cppServer::createSocket::testConnection(int testFD) {
    if( testFD < 0){
        perror("Connection Failed.....\n");
        exit(EXIT_FAILURE);
    }
}

/* Getter Functions */
int cppServer::createSocket::getSock(){
    return sock;
}

struct sockaddr_in cppServer::createSocket::getAddress(){
    return address;
}