#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#define BUFF 2560
int main()
{
        int network_socket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in server;
        server.sin_family=AF_INET;
        server.sin_port=htons(3080);
        server.sin_addr.s_addr=htons(INADDR_ANY);
        bind(network_socket,(struct sockaddr*)&server,sizeof(server));
        listen(network_socket,20);
        int client=accept(network_socket,NULL,NULL);
        char filename[BUFF];
        int reqt;
        recv(client,&reqt,sizeof(reqt),0);
        if(reqt==1)
        {
                recv(client,&filename,BUFF,0);
                char path[100]= "/home/sf32@sfdc.audcse/networks";
                chdir(path);
                int fp=open(filename,0);
                char data[BUFF*4];
                if(fp==-1)
                        printf("File not found\n");
                else
          read(fp,data,sizeof(data));
                send(client,data,BUFF*4,0);
        }
        else if(reqt==2)
        {
                recv(client,&filename,BUFF,0);
                struct stat sb;
                stat(filename,&sb);
                char data[BUFF*4];
                strcpy(data,ctime(&sb.st_mtime));
                printf("%s",data);
                send(client,data,BUFF*4,0);
        }
        return 0;
}
                          
