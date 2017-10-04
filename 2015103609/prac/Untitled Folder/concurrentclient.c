#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
int main()
{
	char fname[200],buf1[2000];
	int s2=socket(AF_INET,SOCK_STREAM,0);
	if(s2==-1)
		printf("socket creation failed");
	struct sockaddr_in s;
	s.sin_family=AF_INET;
	s.sin_port=4300;
	s.sin_addr.s_addr=INADDR_ANY;
	int c=connect(s2,(struct sockaddr*)&s,sizeof(s));
	while(1)
	{
		scanf("%s",buf1);
		if(strcmp(buf1,"bye")==0)
			break;
		send(s2,buf1,sizeof(buf1),0);
		recv(s2,buf1,sizeof(buf1),0);
		printf("%s\n",buf1);
	}
	return 0;
}

