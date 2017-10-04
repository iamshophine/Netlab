#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define HOST_PORT 4444
int main(){
	int fd,n,n1;
	char host[1024],ip[1024],file[1024];
	struct sockaddr_in ans,ins;
	fd=socket(AF_INET,SOCK_DGRAM,0);
	if(fd!=0)
		printf("\nsocket connection working\n");
         ans.sin_family=AF_INET;
        ans.sin_port=HOST_PORT;
        ans.sin_addr.s_addr=INADDR_ANY;
//	bind(fd,(struct sockaddr*)&ans,sizeof(ans));
	n1=sizeof(ins);n=sizeof(ans);
//	while(1){
		strcpy(ip," ");
		FILE *fp = fopen("anscache.txt","r");
	recvfrom(fd,host,sizeof(host),0,(struct sockaddr*)&ans,&n);
		while(!feof(fp)){

			fscanf(fp,"%s",file);
			if(strcmp(file,host)==0){
				fscanf(fp,"%s",ip);
				break;
			}
		}
		if(strcmp(ip," ")==0){
			strcpy(ip,"ERROR : 404 NOT FOUND");
}
		fclose(fp);
		sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&ans,n);
	
	return 0;
}
