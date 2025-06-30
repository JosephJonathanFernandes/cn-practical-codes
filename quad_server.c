#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define port 7079

int main(){
    int server_fd,client_fd;
    struct sockaddr_in servaddr;
    server_fd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(port);
    servaddr.sin_addr.s_addr=INADDR_ANY;

    bind(server_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(server_fd,1);

    client_fd=accept(server_fd,NULL,NULL);

    float a,b,c,d,root1,root2;

    read(client_fd,&a,sizeof(a));
    read(client_fd,&b,sizeof(b));
    read(client_fd,&c,sizeof(c));
    

    d=b*b-4*a*c;

    if(d<0){
        write(client_fd,"Imaginary roots",16);
    }
    else{
         root1 = (-b + sqrt(d)) / (2*a);
        root2 = (-b - sqrt(d)) / (2*a);
        char result[100];
        snprintf(result,sizeof(result),"Roots: %.2f and %.2f",root1,root2);
        write(client_fd,result,strlen(result));
    }

    close(client_fd);
    close(server_fd);

    return 0;
}
