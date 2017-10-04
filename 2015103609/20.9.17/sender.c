#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define PORT 8281
int main()
{
	int sockett,connectt;
	char buff[200];
	struct sockaddr_in my;
	sockett=socket(AF_INET,SOCK_STREAM,0);
	if(sockett==-1)
	{
		printf("\nSocket Error!");
	}
	my.sin_family=AF_INET;
	my.sin_port=htons(PORT);
	my.sin_addr.s_addr=INADDR_ANY;
	connectt=connect(sockett,(struct sockaddr*)&my,sizeof(struct sockaddr));
	if(connectt==-1)
	{
		printf("\nConnect Error!");
	}
	
	//code{
	int sws[4],data[10];
	int i;	
	for(i=0;i<10;i++)
	{
		printf("\nEnter the data(%d) : ",i+1);
		scanf("%d",&data[i]);
	}
	for(i=0;i<10;i++)
	{
		printf("\nEnter the data(%d) : %d ",i+1,data[i]);
	
	}
	send(sockett,data,sizeof(data),0);
	printf("\nData Sent!");
	int flag=0;
	i=0;
	while(i<10)
	{
		sws[i%4]=data[i];
		if(i%4==0||i==9)
		{
			send(sockett,sws,sizeof(sws),0);
			
		}
		i++;
	}
	//}
	return 0;
}
