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

    int n,arr[100],swapped,t;
    
    read(client_fd,&n,sizeof(n));

    read(client_fd,arr,n*sizeof(int));


    for(int i=0;i<n;i++){
        swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                swapped=1;

            }
            
        }
        if(!swapped)
            break;
    }

    write(client_fd,arr,n*sizeof(int));
    

    close(client_fd);
    close(server_fd);

    return 0;
}
    
    