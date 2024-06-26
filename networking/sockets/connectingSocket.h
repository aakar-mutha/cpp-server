
#include <stdio.h>
#include "createSocket.h"


namespace cppServer{
    class connectingSocket: public createSocket {
        public:
            // Constructor 
            connectingSocket(int domain, int service, int protocol, int port, u_long interface);
            
            // Connect to socket in this method.
            int establishConnection(int sock, struct sockaddr_in address);
    };
}