#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8081

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char filename[100], buffer[1024];
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    printf("Enter filename to upload: ");
    scanf("%s", filename);
    write(sockfd, filename, sizeof(filename));

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        write(sockfd, buffer, strlen(buffer));
    }

    fclose(fp);
    close(sockfd);
    return 0;
}
