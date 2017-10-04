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
	char name[1000];
};

main()
{
	struct node *sen;
	sen=(struct node*)malloc(sizeof(struct node));

	int sockfd,newfd,sin_size;
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

	   printf("\nEnter the roll :");
        scanf("%d",&sen->roll);
        printf("\nEnter the name :");
        scanf("%s",sen->name);
        send(newfd,sen,sizeof(struct node),0);        
	   
          recv(newfd,sen,sizeof(struct node),0);
	   printf("\nClient:\n");

             printf("Roll: %d\n",sen->roll);
                 printf("Name: %s\n",sen->name);

              printf("\nRECIEVED\n");	  
}

