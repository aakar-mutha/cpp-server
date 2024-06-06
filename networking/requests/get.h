//
// Created by marketingharp on 6/4/24.
//

#ifndef GET_H
#define GET_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <unordered_map>
#include <Poco/File.h>
#include <Poco/Net/HTTPResponse.h>
#include "../../environment.h"


using namespace std;
namespace cppServer {
    class get {
        public:
            static string handle(string &path, char *contents);
    };
}




#endif //GET_H
