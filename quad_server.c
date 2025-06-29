#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in servaddr;
    float a, b, c, d, root1, root2;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9000);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(server_fd, 1);
    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, &a, sizeof(a));
    read(client_fd, &b, sizeof(b));
    read(client_fd, &c, sizeof(c));

    d = b*b - 4*a*c;

    if (d < 0) {
        write(client_fd, "Imaginary roots", 16);
    } else {
        root1 = (-b + sqrt(d)) / (2*a);
        root2 = (-b - sqrt(d)) / (2*a);
        char result[100];
        snprintf(result, sizeof(result), "Roots: %.2f and %.2f", root1, root2);
        write(client_fd, result, sizeof(result));
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
