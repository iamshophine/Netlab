#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#define HOSTPORT 3031
#define ROOTPORT 3032
int main()
{
	
	struct sockaddr_in client;
	char host[1024],ip[1024],file[1024];
	int fd,n,n1;
	fd=socket(AF_INET,SOCK_DGRAM,0);
	client.sin_family=AF_INET;
	client.sin_port=HOSTPORT;
	client.sin_addr.s_addr=INADDR_ANY;
	printf("\n\nEnter the host name : ");
	scanf("%s",host);
	n=sizeof(client);
	sendto(fd,host,sizeof(host),0,(struct sockaddr*)&client,n);
	recvfrom(fd,ip,sizeof(ip),0,(struct sockaddr*)&client,&n);
	printf("\n\n\nIP : %s",ip);
	return 0;
}

