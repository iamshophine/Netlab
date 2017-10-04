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
	int sockfd,bindd,listenn,connectt;
	struct cse obj;
	char buf2[2000],bufOut[100];
	buf2[2000]='\0';
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
	connectt=connect(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr));
	if(connectt==-1){
		printf("\nError in connecting");
	}else{
		printf("\nConnection success");
	}	


	printf("\nEnter a method : ");
	scanf("%s",obj.method);
	printf("\nEnter the version : ");
	scanf("%s",obj.version);
	printf("\nEnter the url : ");
	scanf("%s",obj.url);
	//send(sockfd,(struct cse*)&obj,sizeof(struct cse),0);
	if(strcmp(obj.method,"get")==0){
		obj.no=0;
		send(sockfd,(struct cse*)&obj,sizeof(struct cse),0);
		int a=recv(sockfd,buf2,2000,0);
		printf("\nThe message received for the mentioned method is ");
		printf("\n%s",buf2);
	}
//	else if(strcmp(obj.method,"post")==0){
		else{
		printf("\nEnter a number to be processed : ");
		scanf("%d",&obj.no);
//		send(sockfd,buf2,2000,0);
		send(sockfd,(struct cse*)&obj,sizeof(struct cse),0);
		int a=recv(sockfd,bufOut,sizeof(bufOut),0);
		printf("\n%s\n",bufOut);
		system("date");
		system("ls -l sample.txt");
	}
	/*else{
	
		printf("\nEnter the valid method!");
	}	*/

	printf("\n");
	return 0;
}
