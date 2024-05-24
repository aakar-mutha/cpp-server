#include <stdio.h>
#include "createSocket.h"
namespace cppServer {
    class bindingSocket : public createSocket {

        public:
            bindingSocket(int domain, int service, int protocol, int port, u_long interface);

            int establishConnection(int sock, struct sockaddr_in address);
    };
}