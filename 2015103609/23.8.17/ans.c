 #include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#define PORT 3034
int main()
{
	
	struct sockaddr_in ans,ins;
	char host[1024],ip[1024],file[1024];
	int fd,n,n2;
	fd=socket(AF_INET,SOCK_DGRAM,0);
	ans.sin_family=AF_INET;
	ans.sin_port=PORT;
	ans.sin_addr.s_addr=INADDR_ANY;
	n=sizeof(ans);
	while(1)
	{
		strcpy(ip,"");
		FILE *fp=fopen("ans.txt","r");
		recvfrom(fd,host,sizeof(host),0,(struct sockaddr*)&ans,&n);
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
			strcpy(ip,"ERROR:404 Not Found");
		}
		fclose(fp);
	
			sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&ans,n);	
	}
	
	return 0;
}

