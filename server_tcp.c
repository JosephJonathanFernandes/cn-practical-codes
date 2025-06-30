// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 5);

    printf("Server is waiting for connection...\n");
    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, buffer, sizeof(buffer));
    printf("Client says: %s\n", buffer);

    char *reply = "Hello from server!";
    send(client_fd, reply, strlen(reply), 0);

    close(client_fd);
    close(server_fd);

    return 0;
}
