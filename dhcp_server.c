#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6767

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server = {AF_INET, htons(PORT), INADDR_ANY}, client;
    socklen_t len = sizeof(client);
    char buf[512];

    bind(sock, (struct sockaddr*)&server, sizeof(server));
    printf("DHCP Server running on port %d...\n", PORT);

    // Step 1: Receive DISCOVER
    recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&client, &len);
    printf("Client: %s\n", buf);

    // Step 2: Send OFFER
    sendto(sock, "OFFER 192.168.1.100", 21, 0, (struct sockaddr*)&client, len);

    // Step 3: Receive REQUEST
    recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&client, &len);
    printf("Client: %s\n", buf);

    // Step 4: Send ACK
    sendto(sock, "ACK 192.168.1.100", 19, 0, (struct sockaddr*)&client, len);

    printf("IP assigned.\n");
    close(sock);
    return 0;
}