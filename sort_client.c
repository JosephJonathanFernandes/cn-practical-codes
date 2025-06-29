#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, arr[10];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9003);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    write(sockfd, arr, sizeof(arr));
    read(sockfd, arr, sizeof(arr));

    printf("Sorted array:\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    close(sockfd);
    return 0;
}
