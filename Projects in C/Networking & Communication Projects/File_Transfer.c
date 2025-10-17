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
    int sockfd, new_sock;
    struct sockaddr_in server, client;
    socklen_t addr_size;
    char buffer[1024];
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8081);
    server.sin_addr.s_addr = INADDR_ANY;
    bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    listen(sockfd, 5);

    printf("Server ready for file transfer...\n");
    addr_size = sizeof(client);
    new_sock = accept(sockfd, (struct sockaddr *)&client, &addr_size);

    fp = fopen("received_file.txt", "w");
    while (recv(new_sock, buffer, sizeof(buffer), 0) > 0)
    {
        fputs(buffer, fp);
        memset(buffer, 0, sizeof(buffer));
    }
    printf("File received successfully!\n");
    fclose(fp);
    close(new_sock);
    close(sockfd);
    return 0;
}
