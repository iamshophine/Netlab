#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<fcntl.h>
#define MYPORT 1313
#define BACKLOG 20
struct node{
	char method[20];
	char file[100];
	char version[20];
	char user_agent[20];
	char server[20];
	char check[50];
	int userpass[50];
	int length;
	char msg[100];
};

main()
{
	struct node dd;
	strcpy(dd.user_agent,"Mozilla/4.0");
	strcpy(dd.server,"Apache/2.2.14"); 
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

	int a = recv(newfd,(struct node *)&dd,sizeof(struct node),0);
	printf("\nMethod Recieved :%s\n",dd.method);

	if (strcmp(dd.method,"get")==0)
	{
		send(newfd,(struct node *)&dd,sizeof(struct node),0);

		int fd ;
		fd = open(dd.file,O_RDWR);
		if (fd<0)
			printf("\nError opening file\n");
		int a=read(fd,buf,2000);
		send (newfd,buf,2000,0);
		printf("\nMessage sent\n");
	}
	else if (strcmp(dd.method,"post")==0)
	{     
		int i;   
		for(i=0;i<dd.length;i++)
		{
			dd.check[i]=dd.userpass[i];
		}
		int flag=0;

		char filename[100]="check.txt",temp[1024];
		FILE *fp=fopen(filename,"r");

		while(fgets(temp,1024,fp)!=NULL)
		{

			if((strstr(temp,dd.check))!=NULL)
			{
				printf("\nCorrect Username and Password\n");
				flag++;
			}
		}
		if(flag==0){
			printf("\nInvalid\n");
			strcpy(dd.msg,"\nIncorrect Username Or Password\n");
			send(newfd,(struct node *)&dd,sizeof(struct node),0);

		}
		else{
			printf("\nValid\n");
			strcpy(dd.msg,"\nSuccessfully Logged In !\n");
			send(newfd,(struct node *)&dd,sizeof(struct node),0);

		}

	}
	else
		printf("\n enter valid method\n");

}
