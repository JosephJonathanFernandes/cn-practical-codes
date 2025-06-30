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

    int key,n,arr[100],found=0,index=-1;
    
    read(client_fd,&n,sizeof(n));

    read(client_fd,arr,n*sizeof(int));

    read(client_fd,&key,sizeof(key));

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            found=1;
             index=i;
            break;
        }
    }

    write(client_fd,&found,sizeof(found));
    write(client_fd,&index,sizeof(index));

    close(client_fd);
    close(server_fd);

    return 0;
}
    
    