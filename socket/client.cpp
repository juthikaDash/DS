#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<string>

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    
    // Communicate with server here
    char message[1024] = "Hello, server!";
    send(clientSocket,message, sizeof(message), 0);
    
    close(clientSocket);
    return 0;
}