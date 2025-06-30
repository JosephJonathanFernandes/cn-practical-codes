#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define port 1825

int main(){
    int server_fd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server={AF_INET,htons(port),INADDR_ANY};

    bind(server_fd,(struct sockaddr*)&server,sizeof(server));
    listen(server_fd,1);
    printf("ftp on port %d ",port);

    int client_fd=accept(server_fd,NULL,NULL);
    printf("client connected");

    send(client_fd,"220 welcome to ftp server\r\n",28,0);
    send(client_fd,"221 goodbye\r\n",13,0);

    close(client_fd);

    close(server_fd);


    return 0;

}