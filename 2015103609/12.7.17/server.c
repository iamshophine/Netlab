#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define MYPORT 3492
#define BACKLOG 110 
int main(){
	int sockfd,bindd,listenn;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		printf("\nError in socket");
	}
	else{
		printf("\nSocket Success");
	}
	
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(MYPORT);
	my_addr.sin_addr.s_addr=inet_addr("192.168.125.14");
	bindd=bind(sockfd,(struct sockaddr*)&my_addr, sizeof(struct sockaddr));
	if(bindd==-1){
		printf("\nError in binding");	
	}else{
		printf("\nBinding success");
	}
	
	listenn=listen(sockfd,BACKLOG);
	if(listenn==-1){
		printf("\nError in listening");
	}else{
		printf("\nSuccess in listening");
	}
	
	int new_fd,sin_size;
	sin_size=sizeof(struct sockaddr_in);
	new_fd=accept(sockfd,(struct sockaddr*)&their_addr,&sin_size);
	if(new_fd==-1){
		printf("\nError in accepting");
	}else{
		printf("\nAccpeting success");
	}
	
	printf("\nEnter a message to the client: ");
	char mess[100],message[100];
	gets(mess);	
	send(new_fd,mess,strlen(mess),0);
	printf("\nMessage Sent to the client!");

	int bytes=recv(sockfd,message,1000,0);
	message[bytes]='\0';
	
	printf("\nMessage from the client : %s",message);

	
	return 0;
}
