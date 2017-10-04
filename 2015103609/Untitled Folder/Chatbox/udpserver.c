//server

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define SERVER 1111
#include<time.h>
int main(){

	int sd,flag=0;
	char msg[1000],buf[1000];
	struct sockaddr_in server;
	int len=sizeof(server);
	sd=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET;
	server.sin_port= SERVER ;
	server.sin_addr.s_addr=INADDR_ANY;

	bind(sd,(struct sockaddr *)&server,len);
	while(1){
    int n=recvfrom(sd,buf,sizeof(buf),0,(struct sockaddr *)&server,&len);
		buf[n]='\0';
		printf("\nClient : %s\n",buf);
		printf("\nServer : ");
                scanf("%s",msg);
                printf("\n");
      sendto(sd,msg,strlen(msg),0,(struct sockaddr *)&server,len);        
      if(strcmp(msg,"bye")==0)
break; 
	}
	close(sd);
	return 0;
}
