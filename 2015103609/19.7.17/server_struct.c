#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define MYPORT 3492
#define BACKLOG 110 
struct sho{
	int no;
	char name[100];
};
int main(){
	int sockfd,bindd,listenn;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	struct sho *obj;
	obj=(struct sho*)malloc(sizeof(struct sho));
	int data1;
	char data2[100];
//	printf("\nEnter the no : ");
//	scanf("%d",&obj->no);
//	printf("\nEnter the name : ");
//	gets(obj->name);
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

	printf("\nEnter the no : ");
	scanf("%d",&obj->no);
	printf("\nEnter the name : ");
	scanf("%s",obj->name);
	send(new_fd,obj,sizeof(struct sho),0);;
	printf("\nSent to client\n");

	
	return 0;
}
