#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define MYPORT 3492
#define BACKLOG 110 
struct cse{
	char method[20];
	char version[20];
	char url[30];
	int no;
};
int main(){
	int sockfd,bindd,listenn;
	struct cse obj;
	char buf[2000];
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
	



	int a=recv(new_fd,(struct cse*)&obj,sizeof(struct cse),0);
	printf("\nMethod received : %s",obj.method);
	

	if(strcmp(obj.method,"get")==0){
		obj.no=0;
		printf("\nfor get method:the file contents will be sent to the client");
		int fd=open(obj.url,O_RDWR);
		if(fd<0){
			printf("\nError opening file");
	
	}
		int a=read(fd,buf,2000);
		printf("\na=%s",buf);
		send(new_fd,buf,2000,0);
	}
//	else if(strcmp(obj.method,"post")==0){
	else{
		printf("\nfor post method the requested info is echoed to client");
		char bufOut[100];
	//	bufOut[100]='\0';
		if(obj.no%2==0){
			strcpy(bufOut,"Even Number");
		}else{
			strcpy(bufOut,"Odd Number");
		}
		send(new_fd,bufOut,sizeof(bufOut),0);
	}
	/*else{
	
		printf("\nEnter the valid method!");
	}	
*/
	printf("\n");
	return 0;
}
