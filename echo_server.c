#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 7070

int main() {
    int server_fd, client_fd;
    struct sockaddr_in servaddr;
    char buffer[100];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(server_fd, 1);
    client_fd = accept(server_fd, NULL, NULL);

    while (1) {
        int n = read(client_fd, buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("Received: %s", buffer);
        write(client_fd, buffer, strlen(buffer));
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
