#include "connectingSocket.h"

cppServer::connectingSocket::connectingSocket(int domain, int service, int protocol, int port, u_long interface) : createSocket(domain, service, protocol, port, interface) {
    setConn(establishConnection(getSock(), getAddress()));
    // testConnection(getConn());
}

int cppServer::connectingSocket::establishConnection(int sock, struct sockaddr_in address) {
    return connect(sock, (struct sockaddr *)& address, sizeof(address));
}