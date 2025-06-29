#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in servaddr;
    int arr[10], key, found = 0;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9002);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(server_fd, 1);
    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, arr, sizeof(arr));
    read(client_fd, &key, sizeof(key));

    for (int i = 0; i < 10; i++) {
        if (arr[i] == key) {
            found = 1;
            break;
        }
    }

    write(client_fd, &found, sizeof(found));
    close(client_fd);
    close(server_fd);
    return 0;
}
