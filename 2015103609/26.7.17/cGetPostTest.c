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
	int sockfd,bindd,listenn,connectt;
	struct cse obj;
	char buf2[20],bufOut[100];
	buf2[20]='\0';
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

	char tempUser[20],tempPass[20];
	printf("\nName : ");
	scanf("%s",tempUser);
	printf("\nPassword  : ");
	scanf("%s",tempPass);	
	int i;
	for(i=0;i<strlen(tempUser);i++)
	{	
		obj.user[i]=(int)tempUser[i];
		
	}
	obj.user[i]='\0';
	int j;
	for(j=0;j<strlen(tempPass);j++)
	{	
		obj.pass[j]=(int)tempPass[j];
		
	}
	obj.pass[j]='\0';
	send(sockfd,(struct cse*)&obj,sizeof(struct cse),0);
		
		int a=recv(sockfd,buf2,20,0);
		printf("\nThe message received for the mentioned method is ");
		printf("\n%s",buf2);

	printf("\n");
	return 0;
}
