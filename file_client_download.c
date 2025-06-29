#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char filename[100], buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    printf("Enter filename to download: ");
    scanf("%s", filename);
    write(sockfd, filename, sizeof(filename));

    printf("File content:\n");
    int n;
    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, n);  // print to stdout
    }

    close(sockfd);
    return 0;
}
