#include <stdio.h>
#include "createSocket.hpp"
namespace cppServer {
    class bindingSocket : public createSocket {

        public:
            bindingSocket(int domain, int service, int protocol, int port, u_long interface);

            int establishConnection(int sock, struct sockaddr_in address);

            // bindingSocket(int domain, int service, int protocol, int port, u_long);
    };
}