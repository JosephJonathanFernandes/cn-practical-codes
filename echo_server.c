#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define port 7075

int main(){
    char buffer[1024];
    int server_fd,client_fd;
    struct sockaddr_in servaddr;
    server_fd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(port);
    servaddr.sin_addr.s_addr=INADDR_ANY;

    bind(server_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(server_fd,1);

    client_fd=accept(server_fd,NULL,NULL);

    while(1){
        int n=read(client_fd,buffer,sizeof(buffer)-1);
        buffer[n]='\0';
        printf("received:%s\n",buffer);
        write(client_fd,buffer,strlen(buffer));
    }
    close(client_fd);
    close(server_fd);
    return 0;
}
