//client
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#define MYPORT 1112
#define BACKLOG 20
#include<fcntl.h>
main()
{
        int sockfd,newfd,sin_size;
        struct sockaddr_in my_addr;
        struct sockaddr_in their_addr;

        sockfd = socket (AF_INET,SOCK_STREAM,0);
        printf("%d\n",sockfd);
        my_addr.sin_family=AF_INET;
        my_addr.sin_port=htons(MYPORT);
        my_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

        if(connect(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1)
                printf("Connect Error");
        else
                printf("Connect Success\n");
 
  char buf[100],msg[200];
  printf("\nEnter the filename : ");
  scanf("%s",msg);
  send(sockfd,msg,200,0);
 int bytes = recv(sockfd,buf,100,0);
 buf[bytes]='\0';
printf("%s",buf);
close(sockfd);
}
