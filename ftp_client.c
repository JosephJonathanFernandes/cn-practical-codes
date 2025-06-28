// ftp_client.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 1825

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);  // Localhost

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    char buffer[1024];
    int n;

    // Receive welcome message
    n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // Receive goodbye message
    n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    close(sock);
    return 0;
}