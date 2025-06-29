#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, a, b, res;
    char op;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9001);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("Enter operator (+ - * /): ");
    scanf(" %c", &op);

    write(sockfd, &a, sizeof(a));
    write(sockfd, &b, sizeof(b));
    write(sockfd, &op, sizeof(op));

    read(sockfd, &res, sizeof(res));
    printf("Result = %d\n", res);

    close(sockfd);
    return 0;
}
