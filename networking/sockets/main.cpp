#include "listeningSocket.h"

using namespace std;

int main(){
    cout << "STARTING...\n ";
    // cppServer::bindingSocket bs = cppServer::bindingSocket(AF_INET, SOCK_STREAM,0,3001,INADDR_ANY);
    // cout <<"socker: "<< bs.getSock() << endl;
    cout << "STARTING LISTENING SOCKET\n";
    cppServer::listeningSocket ls = cppServer::listeningSocket(AF_INET, SOCK_STREAM,0,3001,INADDR_ANY, 10);
    cout << "functions are working!";

}
