#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in servaddr;
    int a, b, res;
    char op;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9001);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(server_fd, 1);
    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, &a, sizeof(a));
    read(client_fd, &b, sizeof(b));
    read(client_fd, &op, sizeof(op));

    switch(op) {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/': res = (b != 0) ? a / b : 0; break;
        default: res = 0;
    }

    write(client_fd, &res, sizeof(res));
    close(client_fd);
    close(server_fd);
    return 0;
}
