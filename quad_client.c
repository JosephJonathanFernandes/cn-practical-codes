#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    float a, b, c;
    char result[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9000);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    printf("Enter coefficients a b c: ");
    scanf("%f %f %f", &a, &b, &c);
    write(sockfd, &a, sizeof(a));
    write(sockfd, &b, sizeof(b));
    write(sockfd, &c, sizeof(c));

    read(sockfd, result, sizeof(result));
    printf("%s\n", result);

    close(sockfd);
    return 0;
}
