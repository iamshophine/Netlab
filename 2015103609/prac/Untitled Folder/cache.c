// web proxy
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<string.h>
#include<netinet/in.h>
#define MYPORT 1112
#define MYPORT2 2223
#define BACKLOG 20
#include<sys/stat.h>
#include<time.h>
struct node{
	int flag;
	char msg[100];
      //  time_t msgtime;
};
main()
{
	time_t msgtime;
	time_t modtime;
	char buf[100],buf2[100],buf3[100],msgt[100],modt[100];
	struct node t;
	int sockfd,newfd,sin_size;
	struct sockaddr_in my_addr;
	struct sockaddr_in my_addr2;
	struct sockaddr_in their_addr;
	sockfd = socket (AF_INET,SOCK_STREAM,0);
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(MYPORT);
	my_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	int sockfd2 = socket(AF_INET,SOCK_STREAM,0);
	my_addr2.sin_family=AF_INET;
	my_addr2.sin_port=htons(MYPORT2);
	my_addr2.sin_addr.s_addr=inet_addr("127.0.0.1");


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

	recv(newfd,t.msg,200,0); 
	int fp = open(t.msg,O_RDWR);
	if(fp < 0)

	{     
		t.flag = 0;      
		printf("\nFile Not Found\n");

		if(connect(sockfd2,(struct sockaddr*)&my_addr2,sizeof(struct sockaddr))==-1)
			printf("Connect Error");
		else
			printf("Connect Success\n");

		send(sockfd2,(struct node *)&t,sizeof(struct node),0);
		int bytes = recv(sockfd2,buf,100,0);
		buf[bytes]='\0';
		printf("\n%s\n",buf);
		int fp2=open(t.msg,O_CREAT|O_RDWR,0666);
		write(fp2,buf,strlen(buf));
		send(newfd,buf,strlen(buf),0);
		printf("\nFile sent\n");

	}
	else
	{     
		t.flag=1;
		struct stat sb;
		stat(t.msg,&sb);
	        modtime =ctime(&sb.st_mtime);
                strcpy(modt,modtime);
		printf("\nModification in proxy : %s\n",modt);
		if(connect(sockfd2,(struct sockaddr*)&my_addr2,sizeof(struct sockaddr))==-1)
			printf("Connect Error");
		else
			printf("Connect Success\n");


     send(sockfd2,(struct node *)&t,sizeof(struct node),0);
    recv(sockfd2,msgt,100,0);
	printf("\nModification in server : %s\n",msgt);

		int cmp = strcmp(modt,msgt);
          		if(cmp!=0)
		{ 
                      t.flag=0;
			printf("\nFile Modified\n");
	send(sockfd2,(struct node *)&t,sizeof(struct node),0);
			recv(sockfd2,buf,100,0);
			system("rm a.txt");
                        printf("File : %s\n",buf);
			int fp2 = open(t.msg,O_CREAT|O_RDWR,0666);
			write(fp2,buf,100,0);
			send(newfd,buf,100,0);
			printf("\n%s\n",buf);
			printf("\nFile sent\n");
		}


		else{
			printf("\nFile not modified\n");
			int fp3 = open (t.msg,O_RDWR);
			char buf3[100];
			read(fp3,buf3,100,0);
			send(newfd,buf,strlen(buf),0);
			printf("\nFile sent\n");

		}
   
	}
 close(sockfd2);
 close(sockfd);
}
