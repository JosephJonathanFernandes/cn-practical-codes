#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8081

int main() {
    int server_fd, client_fd;
    struct sockaddr_in servaddr;
    char filename[100], buffer[1024];
    FILE *fp;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(server_fd, 1);
    printf("File Server ready to receive upload...\n");

    client_fd = accept(server_fd, NULL, NULL);
    read(client_fd, filename, sizeof(filename));
    fp = fopen(filename, "w");

    int n;
    while ((n = read(client_fd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, 1, n, fp);
    }

    fclose(fp);
    close(client_fd);
    close(server_fd);
    return 0;
}
