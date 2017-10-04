//client

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define CLIENT 1111
int main(){

	int sd;
	char msg[1000],buf[1000];
	struct sockaddr_in client;
	int addrlen=sizeof(client);
	sd=socket(AF_INET,SOCK_DGRAM,0);
	client.sin_family=AF_INET;
	client.sin_port= CLIENT;
	client.sin_addr.s_addr=INADDR_ANY;
	while(1){
		printf("\nClient : ");
		scanf("%s",msg);
		printf("\n");
int n= sendto(sd,msg,sizeof(msg),0,(struct sockaddr*)&client,addrlen);
int bytes=recvfrom(sd,buf,sizeof(buf),0,(struct sockaddr*)&client,&addrlen);
		buf[bytes]='\0';
		printf("\nServer : %s\n",buf);
                 if(strcmp(buf,"bye")==0)
                        break;

	}
	close(sd);
	return 0;
}
