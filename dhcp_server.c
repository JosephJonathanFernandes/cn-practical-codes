#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define port 6767

int main(){
int sock=socket(AF_INET,SOCK_DGRAM,0);
struct sockaddr_in server={AF_INET,htons(port),INADDR_ANY},client;
socklen_t len=sizeof(client);

bind(sock,(struct sockaddr*)&server,sizeof(server));
 printf("DHCP Server running on port %d...\n", PORT);

  // Step 1: Receive DISCOVER
  recv(sock,buffer,sizeof(buffer),(struct sockaddr*)&client,&len);
  printf("Client: %s\n", buffer);

// Step 2: Send OFFER
sendto(sock,"OFFER 192.168.1.100",21,0,(struct sockaddr*)&client,len);

 // Step 3: Receive REQUEST
    recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&client, &len);
    printf("Client: %s\n", buffer);

     // Step 4: Send ACK
    sendto(sock, "ACK 192.168.1.100", 19, 0, (struct sockaddr*)&client, len);

    printf("IP assigned.\n");
    close(sock);


    return 0;
}