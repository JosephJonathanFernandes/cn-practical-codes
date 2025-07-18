#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 2525

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(PORT), INADDR_ANY};
    char buffer[1024];

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);
    printf("SMTP Server listening on port %d...\n", PORT);

    int client = accept(server_fd, NULL, NULL);
    printf("Client connected.\n");


    send(client,"220 simple smtp server read\r\n",31,0);

    while(1){
        int len=recv(client,buffer,sizeof(buffer)-1,0);
        buffer[len]='\0';
        printf("client: %s",buffer);

        if(strncmp(buffer,"HELO",4)==0)
        send(client,"250 hello client\r\n",19,0);
     else if (strncmp(buffer, "MAIL FROM", 9) == 0)
            send(client, "250 OK\r\n", 8, 0);
        else if (strncmp(buffer, "RCPT TO", 7) == 0)
            send(client, "250 OK\r\n", 8, 0);
        else if (strncmp(buffer, "DATA", 4) == 0)
            send(client, "354 End data with <CR><LF>.<CR><LF>\r\n", 38, 0);
        else if (strcmp(buffer, ".\r\n") == 0)
            send(client, "250 Message accepted\r\n", 23, 0);
        else if (strncmp(buffer, "QUIT", 4) == 0) {
            send(client, "221 Bye\r\n", 9, 0);
            break;
        } else
            send(client, "500 Command unrecognized\r\n", 27, 0);
    }
        close(client);
        close(server_fd);
    }

    return 0;
}