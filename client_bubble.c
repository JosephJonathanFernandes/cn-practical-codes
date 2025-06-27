#include <stdio.h>

#include  <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <netinet/in.h>



#define PORT 8080

#define max 100



int main() {

    int sock;

    struct sockaddr_in addr;

    int arr[max],n;



    sock=socket(AF_INET,SOCK_STREAM,0);



    addr.sin_family=AF_INET;

    addr.sin_port=htons(PORT);

    inet_pton(AF_INET,"127.0.0.1",&addr.sin_addr);



    connect(sock,(struct sockaddr*)&addr,sizeof(addr));



     printf("Enter number of elements: ");

    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);



    send(sock,&n,sizeof(n),0);

    send(sock,arr,n*sizeof(int),0);



    read(sock,arr,n*sizeof(int));



     printf("Sorted array from server:\n");

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    printf("\n");



    close(sock);

    return 0;

}