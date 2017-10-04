#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#define HOSTPORT 3031
#define ROOTPORT 3032
int main()
{
	
	struct sockaddr_in rns,ins;
	char host[1024],ip[1024],file[1024];
	int fd,n,n1;
	fd=socket(AF_INET,SOCK_DGRAM,0);
	rns.sin_family=AF_INET;
	rns.sin_port=HOSTPORT;
	rns.sin_addr.s_addr=INADDR_ANY;
	ins.sin_family=AF_INET;
	ins.sin_port=ROOTPORT;
	ins.sin_addr.s_addr=INADDR_ANY;
	bind(fd,(struct sockaddr*)&rns,sizeof(rns));
	n1=sizeof(ins);
	n=sizeof(rns);
	while(1)
	{
		strcpy(ip,"");
		FILE *fp=fopen("rns.txt","r");
		recvfrom(fd,host,sizeof(host),0,(struct sockaddr*)&rns,&n);
		while(!feof(fp))
		{
			fscanf(fp,"%s",ip);
			if(strcmp(file,host)==0)
			{
				fscanf(fp,"%s",ip);
				break;
			}
		}
		if(strcmp(ip,".")==0)
		{
			sendto(fd,host,sizeof(host),0,(struct sockaddr*)&ins,n1);
			recvfrom(fd,ip,sizeof(ip),0,(struct sockaddr*)&ins,&n1);
			if(strcmp(ip,"ERROR:404 Not Found")!=0)
			{
				fclose(fp);
				FILE *fp1=fopen("rns.txt","a");
				fputs(host,fp1);
				putc('\n',fp1);
				fputs(ip,fp1);
				putc('\n',fp1);
				fclose(fp1);
			}
			else{
				fclose(fp);
				sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&rns,n);
			}
		}
	}
	return 0;
}

