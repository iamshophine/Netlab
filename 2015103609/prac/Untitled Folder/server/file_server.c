//main server
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<string.h>
#include<netinet/in.h>
#define MYPORT 2223
#define BACKLOG 20
#include<sys/stat.h>
#include<time.h>

struct node{
	int flag;
	char msg[100];
//        time_t msgtime;
};

main()
{      
	struct node t;
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

	recv(newfd,(struct node *)&t,sizeof(struct node),0);
	printf("\nFlag : %d\n",t.flag);

	if(t.flag==0)
	{
		char buf[100];
		int fp = open(t.msg,O_RDWR);
		read(fp,buf,100);
		printf("\n%s",buf);
		send(newfd,buf,100,0);
		printf("\nFile sent\n");

	}
	else if(t.flag == 1)
	{
                printf("\n%s\n",t.msg); 
		struct stat sb;
		stat(t.msg,&sb);
		time_t msgtime = ctime(&sb.st_mtime);
                char msgt[100];
                strcpy(msgt,msgtime);
		printf("\nModification in server : %s\n",msgt);
		send(newfd,msgt,100,0);
    
	}


 recv(newfd,(struct node *)&t,sizeof(struct node),0);
 char buf[100];
                int fp = open(t.msg,O_RDWR);
                read(fp,buf,100);
                printf("\n%s",buf);
                send(newfd,buf,100,0);
                printf("\nFile sent\n");

	
}
