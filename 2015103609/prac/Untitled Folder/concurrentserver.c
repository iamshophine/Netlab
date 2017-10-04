#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
int main()
{
	int c;
	char buf[100];
	struct sockaddr_in s,t;
	int pid;
	int s1=socket(AF_INET,SOCK_STREAM,0);
	if(s1==-1)
	{
		printf("socket not created");
	}
	s.sin_family=AF_INET;
	s.sin_port=4300;
	s.sin_addr.s_addr=INADDR_ANY;
	int b=bind(s1,(struct sockaddr*)&s,sizeof(s));
	printf("\nsocket descriptor%d\n",s1);
	printf("bind %d\n",b);
	int a=listen(s1,5);
	printf("%d\n",a);
	int e=sizeof(t);
	while(1)
	{
		c=accept(s1,(struct sockaddr *)&t,&e);
		printf("Connected\n");
		pid=fork();
		if(pid==0)
		{
			while(1)
			{
				recv(c,buf,sizeof(buf),0);
				if(strcmp(buf,"bye")==0)
				{
					close(c);
					break;
				}
				send(c,"Msg rcvd",20,0);
			}
			exit(0);
		}}
	return 0;
}

