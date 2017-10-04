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
	
	struct sockaddr_in lns,rns;
	char host[1024],ip[1024],file[1024];
	int fd,n,n1;
	fd=socket(AF_INET,SOCK_DGRAM,0);
	lns.sin_family=AF_INET;
	lns.sin_port=HOSTPORT;
	lns.sin_addr.s_addr=INADDR_ANY;
	rns.sin_family=AF_INET;
	rns.sin_port=ROOTPORT;
	rns.sin_addr.s_addr=INADDR_ANY;
	bind(fd,(struct sockaddr*)&lns,sizeof(lns));
	n1=sizeof(rns);
	n=sizeof(lns);
	while(1)
	{
		strcpy(ip,"");
		FILE *fp=fopen("lns.txt","r");
		recvfrom(fd,host,sizeof(host),0,(struct sockaddr*)&lns,&n);
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
			sendto(fd,host,sizeof(host),0,(struct sockaddr*)&rns,n1);
			recvfrom(fd,ip,sizeof(ip),0,(struct sockaddr*)&rns,&n1);
			if(strcmp(ip,"ERROR:404 Not Found")!=0)
			{
				fclose(fp);
				FILE *fp1=fopen("lns.txt","a");
				fputs(host,fp1);
				putc('\n',fp1);
				fputs(ip,fp1);
				putc('\n',fp1);
				fclose(fp1);
			}
			else{
				fclose(fp);
				sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&lns,n);
			}
		}
	}
	return 0;
}

