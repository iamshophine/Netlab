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
        char file[20];
        char version [20];
        char user_agent [20];
        char server[20];
        char date [20];
        char modified_date[20];

};

main()
{
        struct node *dd,*tt;
       dd = (struct node*)malloc(sizeof(struct node));
 tt = (struct node*)malloc(sizeof(struct node));

        int sockfd,sin_size;
        struct sockaddr_in my_addr;
        char buf2[2000];
        buf2[2000]='\0';
        sockfd = socket (AF_INET,SOCK_STREAM,0);
        printf("%d\n",sockfd);
        my_addr.sin_family=AF_INET;


 my_addr.sin_port=htons(MYPORT);
        my_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

        if(connect(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1)
                printf("Connect Error");
        else
                printf("Connect Success\n");

        printf("\nEnter method : get or post\n");
        scanf("%s",dd->method);

  if (strcmp(dd->method,"get")==0)
        {
             send (sockfd,dd,sizeof(struct node),0);
            int a = recv(sockfd,tt,sizeof(struct node),0);
                 printf("\n%s\n",tt->version);
                 printf("\n%s",tt->method);
}
}
