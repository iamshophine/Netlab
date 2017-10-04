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
	char user[20];
	char pass[20];
	
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
	char tempUser[20],tempPass[20];
	int i;
	for(i=0;i<strlen(obj.user);i++)
	{
		tempUser[i]=(char)obj.user[i];
	}	
	tempUser[i]='\0';
	int j;
	for(j=0;j<strlen(obj.pass);j++)
	{
		tempPass[j]=(char)obj.pass[j];
	}	
	tempPass[j]='\0';
	if(strcmp(tempUser,"shophine")||strcmp(tempUser,"ganesh")||strcmp(tempUser,"siva")==0)
	{
	
		if(strcmp(tempPass,"qqq")==0)
		{
			printf("\nValidation success");
			char ji[20]="Welcome";	
			send(new_fd,ji,sizeof(ji),0);
		}
		else{
			char ji[20]="Invalid Password";
			printf("\nInvalid password");
			send(new_fd,ji,sizeof(ji),0);
			
		}
	}else{
		char jii[20]="User not found";
		send(new_fd,jii,sizeof(jii),0);
		printf("\nInvalid user");
	}
	return 0;
}
