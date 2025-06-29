#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 7070

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    while (1) {
        printf("You: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(sockfd, buffer, strlen(buffer));
        read(sockfd, buffer, sizeof(buffer));
        printf("Echo: %s", buffer);
    }

    close(sockfd);
    return 0;
}
