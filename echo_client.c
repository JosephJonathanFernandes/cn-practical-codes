#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define port 7075

int main(){
    int sock_fd;
     char buffer[1024];
    struct sockaddr_in servaddr;
    sock_fd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(port);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    while(1){
        printf("you: ");
        fgets(buffer,sizeof(buffer),stdin);
        write(sock_fd,buffer,strlen(buffer));

         read(sock_fd,buffer,sizeof(buffer));
         printf("Echo: %s\n",buffer);



    }
    close(sock_fd);
    return 0;
}
