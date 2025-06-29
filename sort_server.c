#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in servaddr;
    int arr[10];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9003);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(server_fd, 1);
    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, arr, sizeof(arr));
    sort(arr, 10);
    write(client_fd, arr, sizeof(arr));

    close(client_fd);
    close(server_fd);
    return 0;
}
