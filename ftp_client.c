#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define port 1825

int main(){
    int sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server;

    server.sin_family=AF_INET;
    server.sin_port=htons(port);
    inet_pton(AF_INET,"127.0.0.1",&server.sin_addr);

    connect(sock,(struct sockaddr*)&server,sizeof(server));

    char buffer[1024];
    int n;

    n=recv(sock,buffer,sizeof(buffer)-1,0);
    buffer='\0';
    printf(" %s ",buffer);

    n=recv(sock,buffer,sizeof(buffer)-1,0);
    buffer='\0';
    printf(" %s ",buffer);

    close(sock);

    
    return 0;

}