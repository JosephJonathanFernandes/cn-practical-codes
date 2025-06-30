#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define port 8082

int main(){
    int sock_fd;
     char buffer[1024],filename[1024];
    struct sockaddr_in servaddr;
    sock_fd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(port);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    FILE *fp;

    printf("Enter filename to upload: ");
    scanf("%s", filename);

    write(sock_fd,&filename,sizeof(filename));

     printf("File content:\n");
    int n;

    while((n=read(sock_fd,buffer,sizeof(buffer)))>0)
    fwrite(buffer,1,n,stdout);

    close(sock_fd);

    return 0;
}