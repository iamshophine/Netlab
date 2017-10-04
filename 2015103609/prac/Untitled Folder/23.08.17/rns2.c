#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define HOST_PORT 2222
#define ROOT_PORT 3333
int main(){
	int fd,n,n1;
	char host[1024],ip[1024],file[1024];
	struct sockaddr_in ins,rns;
	fd=socket(AF_INET,SOCK_DGRAM,0);
	if(fd!=0)
		printf("\nsocket connection working\n");
	ins.sin_family=AF_INET;
	ins.sin_port=ROOT_PORT;
	ins.sin_addr.s_addr=INADDR_ANY;
        rns.sin_family=AF_INET;
        rns.sin_port=HOST_PORT;
        rns.sin_addr.s_addr=INADDR_ANY;
//	bind(fd,(struct sockaddr*)&rns,sizeof(rns));
	n1=sizeof(ins);n=sizeof(rns);
       char c[10],c2[10];

		strcpy(ip," ");
		FILE *fp = fopen("rnscache.txt","r");
	recvfrom(fd,host,sizeof(host),0,(struct sockaddr*)&rns,&n);
		while(!feof(fp)){

                       int i,j,len = sizeof(host);
                       for(i=len-4,j=0;i<len;i++,j++){
                                c[j]=host[i];
}
			fscanf(fp,"%s",file);
                        int len2=sizeof(file);
                       for(i=len2-4,j=0;i<len2;i++,j++){
                                c2[j]=host[i];}

			if(strcmp(c,c2)==0){
				fscanf(fp,"%s",ip);
				break;
			}
		}
                  printf("\nIP of .com : %s",ip);
		
		sendto(fd,host,sizeof(host),0,(struct sockaddr*)&ins,n1);
		recvfrom(fd,ip,sizeof(ip),0,(struct sockaddr*)&ins,&n1);
	        if(strcmp(ip,"ERROR : 404 NOT FOUND")==0)
                        {
                            printf("\nIP address not found\n");
                       sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&rns,n);}
 else{
 printf("\nIP address : %s",ip);
            sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&rns,n);
}

	return 0;
}
