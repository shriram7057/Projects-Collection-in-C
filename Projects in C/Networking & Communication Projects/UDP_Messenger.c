#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")  // Link Winsock library
#else
#include <arpa/inet.h>
#include <unistd.h>
#endif
#include <unistd.h>

int main()
{
    int sockfd;
    char buffer[1024];
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("Socket error");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(9090);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (1)
    {
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        // Remove newline from fgets
        buffer[strcspn(buffer, "\n")] = 0;

        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server, sizeof(server)) < 0)
        {
            perror("Send failed");
            continue;
        }

        int n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, NULL, NULL);
        if (n < 0)
        {
            perror("Receive failed");
            continue;
        }

        buffer[n] = '\0'; // Null-terminate the received string
        printf("Server reply: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
