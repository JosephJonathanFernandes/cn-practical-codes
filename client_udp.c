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
    socklen_t len=sizeof(server_addr);

    sockfd=socket(AF_INET,SOCK_DGRAM,0);

    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(PORT);
    inet_pton(AF_INET,"127.0.0.1",&server_addr.sin_addr);

    char *msg = "Hello from client!";
    sendto(sockfd,msg,strlen(msg),0,(struct sockaddr*)&server_addr,len);

    recvfrom(sockfd,buffer,sizeof(buffer),0,NULL,NULL);
     printf("Server says: %s\n", buffer);

     close(sockfd);
     

    return 0;
}