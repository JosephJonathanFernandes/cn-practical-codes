#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 1825

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server = {AF_INET, htons(PORT), INADDR_ANY};

    bind(server_fd, (struct sockaddr*)&server, sizeof(server));
    listen(server_fd, 1);
    printf("FTP Server started on port %d...\n", PORT);

    int client_fd = accept(server_fd, NULL, NULL);
    printf("Client connected.\n");

    send(client_fd, "220 Welcome to FTP server\r\n", 28, 0);
    send(client_fd, "221 Goodbye\r\n", 13, 0);

    close(client_fd);
    close(server_fd);
    return 0;
}