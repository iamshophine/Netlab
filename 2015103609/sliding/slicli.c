#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
int main()
{
        struct sockaddr_in serv_addr;
        int c,i,sockfd;
        char buffer[1024],choice[10];
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_addr.s_addr=INADDR_ANY;
        serv_addr.sin_port=htons(3944);
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd>=0)
                printf("\nSocket created\n");
        printf("%d",sockfd);
        c=connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
        if(c>=0)
                printf("\nConnected\n");
        printf("%d",c);
        while(1)
        {
                recv(sockfd,buffer,1024,0);
                if(strcmp(buffer,"exit")==0)
                {
                        close(sockfd);
                        break;
                }
                printf("\n[%d] The recieved frame is %s\n",i+1,buffer);
                printf("\ndo you want to ack it?\n");
                scanf("%s",choice);
                send(sockfd,choice,sizeof(choice),0);
                if(strcmp(choice,"ack")==0)
                {
                        i++;
                }
        }
        close(sockfd);
}

