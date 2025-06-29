#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, arr[10], key, found;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9002);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    printf("Enter item to search: ");
    scanf("%d", &key);

    write(sockfd, arr, sizeof(arr));
    write(sockfd, &key, sizeof(key));

    read(sockfd, &found, sizeof(found));
    if (found) printf("Item found!\n");
    else printf("Item not found.\n");

    close(sockfd);
    return 0;
}
