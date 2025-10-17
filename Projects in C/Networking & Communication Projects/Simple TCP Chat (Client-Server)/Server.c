#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int sockfd, new_sock;
    struct sockaddr_in server, client;
    char buffer[1024];
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Bind failed");
        exit(1);
    }

    if (listen(sockfd, 5) < 0)
    {
        perror("Listen failed");
        exit(1);
    }

    printf("Server listening on port 8080...\n");

    addr_size = sizeof(client);
    new_sock = accept(sockfd, (struct sockaddr *)&client, &addr_size);
    if (new_sock < 0)
    {
        perror("Accept failed");
        exit(1);
    }

    printf("Client connected!\n");

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        int n = recv(new_sock, buffer, sizeof(buffer) - 1, 0);
        if (n <= 0)
        {
            printf("Client disconnected.\n");
            break;
        }
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        // Remove newline from fgets
        buffer[strcspn(buffer, "\n")] = 0;

        send(new_sock, buffer, strlen(buffer), 0);
    }

    close(new_sock);
    close(sockfd);
    return 0;
}
