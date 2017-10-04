#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define PORT 8080
int main(){
	int i,len,num,rc;
	int server,client;
	char buffer[1024];
	struct sockaddr_in addr,addr2;
	int addrlen=sizeof(addr2);
	server=socket(AF_INET,SOCK_STREAM,0);
	printf("\nsocket connection working");
	// bzero((struct sockaddr*) &addr,sizeof(addr));
	// bzero((struct sockaddr*) &addr2,sizeof(addr2));       

	addr.sin_family=AF_INET;
	addr.sin_port=htons(PORT);
	addr.sin_addr.s_addr=INADDR_ANY;
	bind(server,(struct sockaddr*)&addr,sizeof(addr));
	printf("\nserver binded");
	listen(server,3);
	printf("\nserver listening");
	for(i=0;i<3;i++){
		printf("\niteration %d",i+1);
		printf("\nwaiting on accept");
		client=accept(server,(struct sockaddr *)&addr2,&addrlen);
		printf("\naccept is ok");
		recv(client,buffer,sizeof(buffer),0);
		printf("\nmessage from client:%s",buffer);
		printf("\nechoing to client");
		send(client,buffer,sizeof(buffer),0);
		close(client);
	}
	close(server);
	return 0;
}


