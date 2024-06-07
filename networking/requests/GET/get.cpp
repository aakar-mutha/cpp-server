//
// Created by marketingharp on 6/4/24.
//

#include "get.h"
string cppServer::get::createResponse(int statusCode, char *contentType, char *path)

{
    std::ifstream file(path, std::ios::binary); // Return empty string if unable to open the file
    std::stringstream content;
    content << file.rdbuf();
    file.close();

    std::stringstream response;
    response << "HTTP/1.1 " << statusCode << "\n";
    response << "Content-Type: " << contentType << "\n";
    response << "Content-Length: " << content.str().length() << "\n\n";
    response << content.str();
    return response.str();
}

string cppServer::get::handle(string &path, char *contents)
{

    unordered_map<string, string> contentTypeMap = {
        {".html", "text/html"},
        {".htm", "text/html"},
        {".jpg", "image/jpeg"},
        {".jpeg", "image/jpeg"},
        {".png", "image/png"},
        {".gif", "image/gif"},
        {".css", "text/css"},
        {".js", "application/javascript"},
        {".pdf", "application/pdf"}};

    // Determine content type based on file extension
    std::string contentType = "application/octet-stream"; // Default content type
    std::size_t dotPosition = path.find_last_of('.');
    if (dotPosition != std::string::npos)
    {
        std::string extension = path.substr(dotPosition);
        auto it = contentTypeMap.find(extension);
        if (it != contentTypeMap.end())
        {
            contentType = it->second;
        }
    }
    else
    {
        path.append("/index.html");
        contentType = "text/html";
    }

    string finalPath = BASE_PATH;
    finalPath.append(path);
    // Read the file content into a string
    std::ifstream file(finalPath, std::ios::binary);
    if (!file.is_open())
    {
        char notFoundPath[100] = BASE_PATH;
        strcat(notFoundPath, "/404.html");
        return createResponse(Poco::Net::HTTPResponse::HTTP_NOT_FOUND, "text/html", notFoundPath);
    }

    // Construct the HTTP response

    return createResponse(Poco::Net::HTTPResponse::HTTP_OK, contentType.data(), finalPath.data());
}
