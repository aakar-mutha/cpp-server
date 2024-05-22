#include "bindingSocket.hpp"

cppServer::bindingSocket::bindingSocket(int domain, int service, int protocol, int port, u_long interface) : createSocket(domain, service, protocol, port, interface) {
    setConn(establishConnection(getSock(), getAddress()));
    testConnection(getConn());
}

int cppServer::bindingSocket::establishConnection(int sock, struct sockaddr_in address) {
    return bind(sock, (struct sockaddr *)& address, sizeof(address));