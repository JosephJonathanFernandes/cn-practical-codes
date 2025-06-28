#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5353

typedef struct {
    char domain[50];
    char ip[20];
} DNSRecord;

DNSRecord table[] = {
    {"example.com", "93.184.216.34"},
    {"openai.com",   "104.19.155.92"},
    {"google.com",   "142.250.190.14"},
    {"localhost",    "127.0.0.1"}
};

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server = {AF_INET, htons(PORT), INADDR_ANY}, client;
    socklen_t len = sizeof(client);
    char buffer[100];

    bind(sock, (struct sockaddr*)&server, sizeof(server));
    printf("DNS Server on port %d\n", PORT);

    while (1) {
        int n = recvfrom(sock, buffer, sizeof(buffer)-1, 0, (struct sockaddr*)&client, &len);
        buffer[n] = '\0';
        printf("Query: %s\n", buffer);

        char *response = "Domain not found";
        for (int i = 0; i < 4; i++) {
            if (strcmp(buffer, table[i].domain) == 0) {
                response = table[i].ip;
                break;
            }
        }

        sendto(sock, response, strlen(response), 0, (struct sockaddr*)&client, len);
        printf("Response: %s\n", response);
    }

    close(sock);
    return 0;
}