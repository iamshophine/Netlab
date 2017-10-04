#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#define PORT 5001
#define PORT2 1111
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
	printf("Connected to Client...\n");
	char filename[20];
	int recvbytes=recv(newsd,filename,20,0);
	if(recvbytes==-1)
	{
		printf("Receive Error\n");
		return 0;
	}
	char result[3000],answer[3000];
	int fd=open(filename,O_RDWR | S_IREAD | S_IWRITE);
struct stat sb;
lstat(filename,&sb);

	if(fd==-1)
	{
		int mainsock=socket(AF_INET,SOCK_STREAM,0);
		if(mainsock==-1)
		{
			printf("Server Socket Not Created");
			close(sockid);
			return 0;
		}
		struct sockaddr_in proxyserver;
		proxyserver.sin_family=AF_INET;
		proxyserver.sin_port=htons(PORT2);
		proxyserver.sin_addr.s_addr=INADDR_ANY;
		int i;
		for(i=0;i<8;i++)
			proxyserver.sin_zero[i]='\0';
		int connectstatus;
		connectstatus=connect(mainsock,(struct sockaddr*)&proxyserver,sizeof(struct sockaddr));
		if(connectstatus==-1)
		{
			printf("Connect Error");
			return 0;
		}
		printf("Connected to Main Server....");
		int sentbytes1=send(mainsock,filename,sizeof(filename),0);
		if(sentbytes1==-1)
		{
			printf("Send error from Proxy ");
			return 0;
		}
		char status[]="No";
		sentbytes1=send(mainsock,status,strlen(status),0);
		if(sentbytes1==-1)
		{
			printf("Send Error From Proxy-2");
			return 0;
		}
		int recvbytes=recv(mainsock,answer,3000,0);
		if(recvbytes==-1)
		{
			printf("Receive Error");
			return 0;
		}
		answer[recvbytes]='\0';
		close(mainsock);
		int fd2=open(filename,O_CREAT | O_RDWR);
		if(fd2==-1)
		{
			printf("Error in file creation");
			return 0;
		}
		lseek(fd2,0,0);
		write(fd2,answer,strlen(answer));
		sentbytes1=send(newsd,answer,sizeof(answer),0);
		if(sentbytes1==-1)
		{
			printf("Error sending to client");
			return 0;
		}
	}
	else
	{printf("\n%s",(char *)sb.st_mtime);
		int mainsock=socket(AF_INET,SOCK_STREAM,0);
		if(mainsock==-1)
		{
			printf("Server Socket Not Created");
			close(sockid);
			return 0;
		}
		struct sockaddr_in proxyserver;
		proxyserver.sin_family=AF_INET;
		proxyserver.sin_port=htons(PORT2);
		proxyserver.sin_addr.s_addr=INADDR_ANY;
		int i;
		for(i=0;i<8;i++)
			proxyserver.sin_zero[i]='\0';
		int connectstatus;
		connectstatus=connect(mainsock,(struct sockaddr*)&proxyserver,sizeof(struct sockaddr));
		if(connectstatus==-1)
		{
			printf("Connect Error");
			return 0;
		}
		/*int recvbytes=rec
		  lseek(fd,0,0);
		  read(fd,result,3000);
		  close(fd);
		  int sentbytes=send(newsd,result,sizeof(result),0);
		  if(sentbytes==-1)
		  {
		  printf("Send Error\n");
		  return 0;
		  }*/
		int sentbytes=send(mainsock,filename,sizeof(filename),0);
		if(sentbytes==-1)
		{
			printf("Send Error");
			return 0;
		}
		char status[]="Yes";
		sentbytes=send(mainsock,status,strlen(status),0);
		if(sentbytes==-1)
		{
			printf("Send Error From Proxy-2");
			return 0;
		}
		close(sockid);
	}
	return 0;
}
