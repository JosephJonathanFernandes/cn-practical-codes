#include <stdio.h>

#include  <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <netinet/in.h>



#define PORT 8080

#define max 100



void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++)

        for (int j = 0; j < n - i - 1; j++)

            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;

            }

}



int main() {

    int serve_fd,client_fd;

    struct sockaddr_in addr;

    int arr[max],n;



    serve_fd=socket(AF_INET,SOCK_STREAM,0);



    addr.sin_family=AF_INET;

    addr.sin_addr.s_addr=INADDR_ANY;

    addr.sin_port=htons(PORT);



    bind(serve_fd,(struct sockaddr*)&addr,sizeof(addr));

    listen(serve_fd,5);

     printf("Server waiting for connection...\n");



     client_fd=accept(serve_fd,NULL,NULL);



     read(client_fd,&n,sizeof(n));

     read(client_fd,arr,n*sizeof(int));



     printf("Received array: ");

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);



    bubbleSort(arr, n);  // Sort it



    printf("\nSorted array: ");

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);



    send(client_fd,arr,n*sizeof(int),0);



    close(client_fd);

    close(serve_fd);

    return 0;



}