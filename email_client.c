// smtp_client.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 2525

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    char buffer[1024];

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);  // Connect to localhost

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    // Receive greeting
    int n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // Send HELO
    send(sock, "HELO client\r\n", 13, 0);
    n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // MAIL FROM
    send(sock, "MAIL FROM:<user@example.com>\r\n", 30, 0);
    n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // RCPT TO
    send(sock, "RCPT TO:<receiver@example.com>\r\n", 32, 0);
    n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // DATA
    send(sock, "DATA\r\n", 6, 0);
    n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // Email body
    send(sock, "Subject: Test Mail\r\nThis is a test.\r\n.\r\n", 41, 0);
    n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // QUIT
    send(sock, "QUIT\r\n", 6, 0);
    n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    close(sock);
    return 0;
}