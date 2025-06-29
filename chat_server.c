#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 9090

void *receive(void *sock) {
    int fd = *(int*)sock;
    char msg[100];
    while (1) {
        read(fd, msg, sizeof(msg));
        printf("\nClient: %s\n", msg);
    }
    return NULL;
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in servaddr;
    char msg[100];
    pthread_t recv_thread;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(server_fd, 1);
    client_fd = accept(server_fd, NULL, NULL);

    pthread_create(&recv_thread, NULL, receive, &client_fd);

    while (1) {
        printf("You: ");
        fgets(msg, sizeof(msg), stdin);
        write(client_fd, msg, strlen(msg));
    }

    close(server_fd);
    return 0;
}
