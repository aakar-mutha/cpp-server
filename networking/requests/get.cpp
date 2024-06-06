//
// Created by marketingharp on 6/4/24.
//

#include "get.h"


string cppServer::get::handle(string &path, char* contents){
    string finalPath = BASE_PATH;
    finalPath.append(path);
    // cout << "route is: " << path << endl;

    // Poco::File htmlFile(path);
    
    // if(htmlFile.exists() && htmlFile.canRead()){
    //     ifstream file(path, ios::binary);
    //     file.seekg(0, ios::end);
    //     streampos fileSize = file.tellg();
    //     file.seekg(0, ios::beg);
    //     // Read the file contents into the buffer
    //     file.read(contents, fileSize);
    //     // Close the file
    //     file.close();

    //     return EXIT_SUCCESS;
    // }
    // else {
    //     return EXIT_FAILURE;
    // }


    std::unordered_map<std::string, std::string> contentTypeMap = {
        {".html", "text/html"},
        {".htm", "text/html"},
        {".jpg", "image/jpeg"},
        {".jpeg", "image/jpeg"},
        {".png", "image/png"},
        {".gif", "image/gif"},
        {".css", "text/css"},
        {".js", "application/javascript"}
        // Add more mappings as needed
    };

    // Determine content type based on file extension
    std::string contentType = "application/octet-stream"; // Default content type
    std::size_t dotPosition = finalPath.find_last_of('.');
    if (dotPosition != std::string::npos) {
        std::string extension = finalPath.substr(dotPosition);
        auto it = contentTypeMap.find(extension);
        if (it != contentTypeMap.end()) {
            contentType = it->second;
        }
    }
    else{
        finalPath.append("/index.html");
        contentType = "text/html";
    }

    // Read the file content into a string
    std::ifstream file(finalPath, std::ios::binary);
    if (!file.is_open()) {
        string notFoundPath = BASE_PATH;
        notFoundPath.append("/404.html");
        std::ifstream file(notFoundPath, std::ios::binary); // Return empty string if unable to open the file
        contentType = "text/html";
        std::stringstream content;
        content << file.rdbuf();
        file.close();
        std::stringstream response;
        response << "HTTP/1.1 " << Poco::Net::HTTPResponse::HTTP_NOT_FOUND << "\n";
        response << "Content-Type: " << contentType << "\n";
        response << "Content-Length: " << content.str().length() << "\n\n";
        response   << content.str();

    return response.str();        
    }
    if(file.fail()){
        
    }

    std::stringstream content;
    content << file.rdbuf();
    file.close();

    // Construct the HTTP response
    std::stringstream response;
    response << "HTTP/1.1 " << Poco::Net::HTTPResponse::HTTP_OK << "\n";
    response << "Content-Type: " << contentType << "\n";
    response << "Content-Length: " << content.str().length() << "\n\n";
    response << content.str();

    return response.str();
}