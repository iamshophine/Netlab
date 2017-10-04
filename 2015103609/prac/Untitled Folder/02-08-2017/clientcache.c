#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define BUFF 2560
int main()
{
        int network_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in server;
        server.sin_family=AF_INET;
        server.sin_port=htons(3000);
        server.sin_addr.s_addr=htons(INADDR_ANY);
        if(connect(network_socket,(struct sockaddr*)&server, sizeof(server)))
        printf("Connection Error\n");
        char filename[BUFF];
        printf("Enter the name of the file\n");
        fgets(filename,BUFF,stdin);
        filename[strcspn(filename,"\r\n")]=0;
        send(network_socket,filename,BUFF,0);
        char data[BUFF*4];
        recv(network_socket,&data,BUFF*4,0);
        if(strcmp(data,"\0")==0)
                printf("File not found in server\n");
        else
                printf("%s\n",data);
        return 0;
}

