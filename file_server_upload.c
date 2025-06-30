#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define port 8081

int main(){
    char buffer[1024],filename[1024];
    FILE *fp;
    int server_fd,client_fd;
    struct sockaddr_in servaddr;
    server_fd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(port);
    servaddr.sin_addr.s_addr=INADDR_ANY;

    bind(server_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(server_fd,1);
    printf("File Server ready to receive upload...\n");


    client_fd=accept(server_fd,NULL,NULL);
    read(client_fd,&filename,sizeof(filename));
    fp=fopen(filename,"w");
    
    int n;
    while((n=read(client_fd,buffer,sizeof(buffer)))>0){
        fwrite(buffer,1,n,fp);
    }

    fclose(fp);
    close(client_fd);
    close(server_fd);

    return 0;
}