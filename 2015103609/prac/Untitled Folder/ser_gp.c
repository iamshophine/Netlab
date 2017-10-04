#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<fcntl.h>
#define MYPORT 2222
#define BACKLOG 20
struct node{
        char method[20];
        char version[20];
        char file[20];
        char user_agent[20];
        char server[20];
        char date[20];
        char modified_date[20];

};

main()
{
        struct node *dd,*tt;
        dd=(struct node *)malloc(sizeof(struct node));
 tt=(struct node *)malloc(sizeof(struct node));

        strcpy(tt->version,"HTTP/1.1");
        strcpy(tt->user_agent,"Mozilla/4.0");
        strcpy(tt->server,"Apache/2.2.14");
       
        int sockfd,newfd,sin_size;
        char buf[2000];
        struct sockaddr_in my_addr;
        struct sockaddr_in their_addr;
        sockfd = socket (AF_INET,SOCK_STREAM,0);


 printf("%d\n",sockfd);
        my_addr.sin_family=AF_INET;
        my_addr.sin_port=htons(MYPORT);
        my_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

        if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1)
                printf("Bind Error\n");
        else
                printf("Bind Success\n");
        if (listen(sockfd,BACKLOG)==-1)
                printf("Listen Error\n");
        else
                printf("Listen Success\n");

        sin_size =  sizeof(struct sockaddr*);

        newfd=accept(sockfd,(struct sockaddr*)&their_addr,&sin_size);

       int a = recv(newfd,dd,sizeof(struct node),0);
     printf("\nMethod Recieved :%s\n",dd->method);

  if (strcmp(dd->method,"get")==0)
        {
             
               send(newfd,tt,sizeof(struct node),0);

}

 else if (strcmp(dd->method,"post")==0)
        {

        }
        else
                printf("\n enter valid method\n");

}

