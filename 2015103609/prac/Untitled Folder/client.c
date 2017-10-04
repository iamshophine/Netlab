#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#define MYPORT 1313
#define BACKLOG 20
struct node{
        int roll;
        char name[100];
};
main()
{
       struct node *rec;
       rec = (struct node*)malloc(sizeof(struct node));
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

	       	recv(sockfd,rec,sizeof(struct node),0);
               printf("\nServer:\n");
                 printf("Roll: %d\n",rec->roll);
                 printf("Name: %s\n",rec->name);

                    printf("\nEnter the roll :");
        scanf("%d",&rec->roll);
        printf("\nEnter the name :");
        scanf("%s",rec->name);
        send(sockfd,rec,sizeof(struct node),0);
		printf("\nSENT\n");

}



