#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<time.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#define PORT 1111
int main()
{
	int sockid;
	sockid=socket(AF_INET,SOCK_STREAM,0);
	if(sockid==-1)
	{
		printf("Socket Error");
		return 0;
	}
	struct sockaddr_in server,dummy;
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=INADDR_ANY;
	int bindstatus=bind(sockid,(struct sockaddr*)&server,sizeof(struct sockaddr));
	if(bindstatus==-1)
	{
		printf("Bind Error");
		return 0;
	}
	int listenstatus=listen(sockid,10);
	if(listenstatus==-1)
	{
		printf("Listen Error");
		return 0;
	}
	int size=sizeof(struct sockaddr);
	int newsd=accept(sockid,(struct sockaddr*)&dummy,&size);
	if(newsd==-1)
	{
		printf("Accept Error");
		return 0;
	}
	printf("Connected to Proxy Client...\n");
	char filename[20];
	int recvbytes=recv(newsd,filename,20,0);
	if(recvbytes==-1)
	{
		printf("Receive Error\n");
		return 0;
	}
struct stat sb;
lstat(filename,&sb);

	char status[20];
	recvbytes=recv(newsd,status,20,0);
	status[recvbytes]='\0';
	printf("%s\n",filename);
	int fd=open(filename,O_RDWR | S_IREAD | S_IWRITE);
	if(fd==-1)
	{
		printf("File not found");
		perror("fd");
		close(sockid);
		return 0;
	}
	lseek(fd,0,0);
	char result[3000];
	read(fd,result,3000);
printf("\n%s",(char*)sb.st_mtime);	
close(fd);
	if(status[0]=='N')
	{
		int sentbytes=send(newsd,result,sizeof(result),0);
		if(sentbytes==-1)
		{
			printf("Send Error\n");
			return 0;
		}
	}
	else
	{
		//printf("%s",filename);
		struct stat sb;
		stat(filename,&sb);
		printf("%s",ctime(&sb.st_mtime));
	}
	close(sockid);
	return 0;
}
