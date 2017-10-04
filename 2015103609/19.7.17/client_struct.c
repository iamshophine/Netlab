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
	int sockfd,connectt;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	struct sho *obj;
	obj=(struct sho*)malloc(sizeof(struct sho));
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
	
	connectt=connect(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr));
	if(connectt==-1){
		printf("\nError in connecting");
	}else{
		printf("\nConnection success");
	}
	
	char mess[100],message[100];
	int bytes=recv(sockfd,obj,sizeof(struct sho),0);
	printf("\nReceived from Server :\n\tNumber :  %d\n\tName : %s\n",obj->no,obj->name);
		
return 0;
	}
