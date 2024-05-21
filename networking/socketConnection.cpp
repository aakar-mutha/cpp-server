/*
Created By : Aakar Mutha 
Date: 05/21/2024
File: socketConnection.cpp
*/
#include "socketConnection.hpp"

cppServer::socketConnection::socketConnection(int domain, int service, int protocol, int port, unsigned long interface){
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

    // conn is either bind or connect.
    conn = establishConnection(sock, address);
    testConnection(conn);

}

/* Test if the connection was successful. */
void cppServer::socketConnection::testConnection(int testFD) {
    if( testFD < 0){
        perror("Connection Failed.....");
        exit(EXIT_FAILURE);
    }
}

/* Getter Functions */
int cppServer::socketConnection::getSock(){
    return sock;
}

int cppServer::socketConnection::getConn(){
    return conn;
}

struct sockaddr_in cppServer::socketConnection::getAddress(){
    return address;
}

