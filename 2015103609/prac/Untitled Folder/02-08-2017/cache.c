#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<fcntl.h>
#define BUFF 2560
int main()
{
        char *ld;
        int network_socket=socket(AF_INET,SOCK_STREAM,0);
        int sock=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in server,mserver;
        server.sin_family=AF_INET;
        server.sin_port=htons(3000);
        server.sin_addr.s_addr=htons(INADDR_ANY);
        mserver.sin_family=AF_INET;
        mserver.sin_port=htons(3080);
        if(connect(sock,(struct sockaddr*)&mserver, sizeof(mserver)))
                printf("Connection Error with server\n");
        mserver.sin_addr.s_addr=htons(INADDR_ANY);
        bind(network_socket,(struct sockaddr*)&server,sizeof(server));
        listen(network_socket,20);
        int client=accept(network_socket,NULL,NULL);
        char filename[BUFF];
        recv(client,&filename,BUFF,0);
        int fp=open(filename,0);
        char data[BUFF*4];
  if(fp==-1)
        {
                int reqtype=1;
                send(sock,&reqtype,sizeof(reqtype),0);
                printf("File not found in cache\n");
                send(sock,filename,BUFF,0);
                char data[BUFF*4];
                recv(sock,&data,BUFF*4,0);
                int fs=open(filename, O_CREAT | O_RDWR);
                write(fs,data,sizeof(data));
                if(strcmp(data,"\0")==0)
                        printf("File not found in server\n");
                else
                        send(client,data,BUFF*4,0);
        }
        else
        {
                int reqtype=2;
                send(sock,&reqtype,sizeof(reqtype),0);
                send(sock,filename,BUFF,0);
                struct stat sb;
                stat(filename,&sb);
                char c[100];
                strcpy(c,ctime(&sb.st_mtime));
                printf("Last file modification:   %s", c);
                send(sock,filename,BUFF,0);
                char data[BUFF*4];
                recv(sock,&data,BUFF*4,0);
                int d=strcmp(data,c);
                if(d==0)
                {
                        read(fp,data,sizeof(data));
                        send(client,data,BUFF*4,0);
                }
		 else
                {
                        int reqtype=1;
                        send(sock,&reqtype,sizeof(reqtype),0);
                        send(sock,filename,BUFF,0);
                        char data[BUFF*4];
                        recv(sock,&data,BUFF*4,0);
                        int fs=open(filename, O_CREAT | O_RDWR);
                        write(fs,data,sizeof(data));
                        send(client,data,BUFF*4,0);
                }
        }
        return 0;
}

