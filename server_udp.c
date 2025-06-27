// server_udp.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080

int main() {

    int sockfd;
    char buffer[1024];
    struct sockaddr_in server_addr,client_addr;
    socklen_t len=sizeof(client_addr);

    sockfd=socket(AF_INET,SOCK_DGRAM,0);

    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY;
    server_addr.sin_port=htons(PORT);

    bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));

    printf("Server waiting for message...\n");
    recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client_addr,&len);
     printf("Client says: %s\n", buffer);

    char *reply = "Hello from server!";

    sendto(sockfd,reply,strlen(reply),0,(struct sockaddr*)&client_addr,len);

    close(sockfd);
    return 0;

    return 0;
}