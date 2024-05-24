//
// Created by Aakar Mutha on 5/22/24.
//

#ifndef LISTENINGSOCKET_HPP
#define LISTENINGSOCKET_HPP

#include <stdio.h>
#include "bindingSocket.h"

namespace cppServer
{

    class listeningSocket : public bindingSocket
    {   
        private:

            int backlog;
            
            int listening;
        public:

            listeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg);

            void startListening();
    };

}
#endif // LISTENINGSOCKET_HPP
