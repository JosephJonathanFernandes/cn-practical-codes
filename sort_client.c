#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define port 7079

int main(){
    int sock_fd;
    struct sockaddr_in servaddr;
    sock_fd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(port);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));

  int n;
    int arr[100];
 printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter n integers:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    


    write(sock_fd,&n,sizeof(n));
    write(sock_fd,arr,n*sizeof(int));
    

    read(sock_fd,arr,n*sizeof(int));
     printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
   
    close(sock_fd);
    return 0;
}