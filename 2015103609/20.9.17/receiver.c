#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8281
int main()
{
	int sockett,bindd,listenn,acceptt;
	struct sockaddr_in my,they;
	char buff[200];
	sockett=socket(AF_INET,SOCK_STREAM,0);
	if(sockett==-1)
	{
		printf("\nSocket Error\n");
	}
	my.sin_family=AF_INET;
	my.sin_port=htons(PORT);
	my.sin_addr.s_addr=INADDR_ANY;
	bindd=bind(sockett,(struct sockaddr*)&my,sizeof(struct sockaddr));
	if(bindd==-1)
	{
		printf("\nBind Error!");	
	}
	listenn=listen(sockett,110);
	if(listenn==-1)
	{
		printf("\nListen Error!");
	}
	int siz;
	siz=sizeof(struct sockaddr_in);
	acceptt=accept(sockett,(struct sockaddr*)&they,&siz);
	if(acceptt==-1)
	{
		printf("\nAccept Error!");
	}
	//code{
	int data[10];
	int i=0;
	/*recv(acceptt,data,sizeof(data),0);
	printf("\nReceived Data : \n");
	int i;
	for(i=0;i<10;i++)
	{
		printf("\nData(%d) = %d",i+1,data[i]);
		
	}*/

	int rws[4];
	recv(acceptt,rws,sizeof(rws),0);
	int k,r=0;
	for(r=0;r<3;r++){
		for(k=0;k<4;k++)
		{
			data[i]=rws[k];
			i++;
			//if(i==10)
			//{
			//	break;
			//}
		}
		recv(acceptt,rws,sizeof(rws),0);
	}
	

	printf("\nReceived Data : \n");
	int x;
	for(x=0;x<10;x++)
	{
		printf("\nData(%d) = %d",x+1,data[x]);
		
	}
	//}
	return 0;
}
