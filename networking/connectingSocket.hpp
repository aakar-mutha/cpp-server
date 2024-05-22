
#include <stdio.h>
#include "socketConnection.hpp"


namespace cppServer{
    class connectingSocket: public socketConnection {
        public:
            // Constructor 
            connectingSocket(int domain, int service, int protocol, int port, u_long interface);
            
            // Connect to socket in this method.
            int establishConnection(int sock, struct sockaddr_in address);
    };
}