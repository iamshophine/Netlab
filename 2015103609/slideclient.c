#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#define PORT 6969
int main()
{
        int sock,bytes_received,size,i=1,con;
        char receive[30];
        struct sockaddr_in s;
        if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
        {
                perror("Socket not created\n");
                exit(1);
        }
        printf("Socket created\n");
        s.sin_family=AF_INET;
        s.sin_port=htons(PORT);
        s.sin_addr.s_addr=htons(INADDR_ANY);
        con=connect(sock,(struct sockaddr*)&s,sizeof(s));
        if(con==-1)
        {
                printf("Connect error\n");
                exit(1);
        }
        while(1)
        {
                memset(receive,0,sizeof receive);
                recv(sock,receive,25,0);
                if(strcmp(receive,"exit")==0)
                {
                        close(sock);
                        break;
                }
                else
                {
                        if(strlen(receive)<=10)
                        {
                                printf("Frame %d data %s received\n",i,receive);
                                send(sock,receive,strlen(receive),0);
                        }
                        else
                        {
                                send(sock,"negative",strlen("negative"),0);
                        }
                        i++;
                }
        }
        close(sock);
        return(0);
}

