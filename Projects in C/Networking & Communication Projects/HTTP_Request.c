#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")  // Link Winsock library
#else
#include <arpa/inet.h>
#include <unistd.h>
#endif


int main()
{
    int sockfd;
    struct sockaddr_in server;
    char request[1024], response[4096];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr.s_addr = inet_addr("93.184.216.34"); // example.com IP

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Connect failed");
        exit(1);
    }

    strcpy(request, "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n");
    send(sockfd, request, strlen(request), 0);
    recv(sockfd, response, sizeof(response), 0);
    printf("%s\n", response);

    close(sockfd);
    return 0;
}
