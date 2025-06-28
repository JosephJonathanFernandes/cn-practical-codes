// dns_client.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5353

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server;
    socklen_t len = sizeof(server);
    char buffer[100], response[100];

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);  // Localhost

    printf("Enter domain name to resolve: ");
    scanf("%s", buffer);

    sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&server, len);

    int n = recvfrom(sock, response, sizeof(response) - 1, 0, (struct sockaddr*)&server, &len);
    response[n] = '\0';

    printf("IP Address: %s\n", response);

    close(sock);
    return 0;
}