#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6767

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server = {AF_INET, htons(PORT)};
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    char buf[512];
    socklen_t len = sizeof(server);

    // Step 1: Send DISCOVER
    sendto(sock, "DISCOVER", 8, 0, (struct sockaddr*)&server, len);
    printf("Sent: DISCOVER\n");

    // Step 2: Receive OFFER
    recvfrom(sock, buf, sizeof(buf), 0, NULL, NULL);
    printf("Server: %s\n", buf);

    // Step 3: Send REQUEST
    sendto(sock, "REQUEST 192.168.1.100", 22, 0, (struct sockaddr*)&server, len);
    printf("Sent: REQUEST\n");

    // Step 4: Receive ACK
    recvfrom(sock, buf, sizeof(buf), 0, NULL, NULL);
    printf("Server: %s\n", buf);

    close(sock);
    return 0;
}