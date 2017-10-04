#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define PORT 1234
int main(){
	int fd,n;
	char host[1024],ip[1024],s[1024];
	struct sockaddr_in server;
	fd=socket(AF_INET,SOCK_DGRAM,0);
	if(fd!=0)
		printf("\nsocket connection working\n");
	server.sin_family=AF_INET;
	server.sin_port=PORT;
	server.sin_addr.s_addr=INADDR_ANY;
//	bind(fd,(struct sockaddr*)&server,sizeof(server));
	n=sizeof(server);
	printf("\nEnter the url :\n");
	scanf("%s",host);
        strcpy(ip," ");
	sendto(fd,host,sizeof(host),0,(struct sockaddr*)&server,n);
	recvfrom(fd,ip,sizeof(ip),0,(struct sockaddr*)&server,&n);
     //  strcpy(ip," ");
	printf("\nIP : %s",ip);
	return 0;
}
