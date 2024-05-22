/*
Created By : Aakar Mutha 
Date: 05/21/2024
File: socketConnection.hpp
*/

#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

namespace cppServer {

    class socketConnection{
        private:
            int sock;
            struct sockaddr_in address;
            int conn;
        public:
            socketConnection(int domain, int service, int protocol, int port, u_long interface);

            virtual int establishConnection(int sock, struct sockaddr_in address) = 0;
            
            /* Test if the connection was successful. */
            void testConnection(int testFD);

            /* Getter Functions */
            int getSock();

            int getConn();

            struct sockaddr_in getAddress();

            /* Setter Function */
            void setConn(int connection);
            
    };
}