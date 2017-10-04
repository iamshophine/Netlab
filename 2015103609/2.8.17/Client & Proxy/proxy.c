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
#define NEWPORT 3609
#define BACKLOG 110 
int main(){
	int sockfd,bindd,listenn,connectt;
	struct sockaddr_in my_addr;
	struct sockaddr_in my_addr2;
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
	
	my_addr2.sin_family=AF_INET;
	my_addr2.sin_port=htons(NEWPORT);
	my_addr2.sin_addr.s_addr=inet_addr("192.168.125.14");


	int sockfdd,connecttt;
	//struct sockaddr_in my_addr2;
	//struct sockaddr_in their_addr2;

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
	char file[20],message[200];
	int bytes=recv(new_fd,file,20,0);
	file[bytes]='\0';
	int fd;
	fd=open(file,O_RDWR);
	if(fd<0){
		printf("\nError opening the file");

		
	sockfdd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfdd==-1){
		printf("\nError in PROXY socket");
	}
	else{
		printf("\nPROXY Socket Success");
	}
	
	connecttt=connect(sockfdd,(struct sockaddr*)&my_addr2,sizeof(struct sockaddr));
	if(connecttt==-1){
		printf("\nError in PROXY connecting");
	}else{
		printf("\nPROXY Connection success");
	}
		
		send(sockfdd,file,sizeof(file),0);
		
		char file2[20],message2[200];
	int bytes2=recv(sockfdd,file2,20,0);
	file2[bytes2]='\0';
	printf("\nContent from main server : %s",file2);

	}else{
		int len=read(fd,message,200);
		if(len<0){
			printf("\nError reading the file");
			return;
		}
		message[len]='\0';
		send(new_fd,message,sizeof(message),0);


	}
	
	return 0;
}
