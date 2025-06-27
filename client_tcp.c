// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock;
    struct sockaddr_in addr;
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr); // localhost

    connect(sock, (struct sockaddr*)&addr, sizeof(addr));

    char *msg = "Hello from client!";
    send(sock, msg, strlen(msg), 0);

    read(sock, buffer, sizeof(buffer));
    printf("Server says: %s\n", buffer);

    close(sock);

    return 0;
}
