#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#define PORT 8080
int main(){
	int client;
	char send_buf[100];
	char recv_buf[100];
	struct sockaddr_in addr;
	client=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(PORT);
	addr.sin_addr.s_addr=INADDR_ANY;
	connect(client,(struct sockaddr *)&addr,sizeof(addr));
	printf("\nenter the string:");
	scanf("%s",send_buf);
	send(client,send_buf,strlen(send_buf),0);
	recv(client,recv_buf,strlen(recv_buf),0);
	printf("\nmessage received %s",recv_buf);
	close(client);
	return 0;
}

