#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
int main()
{
	char buf[2000],buf2[2000];
	int s2=socket(AF_INET,SOCK_STREAM,0);
	if(s2==-1)
		printf("socket creation failed");
	struct sockaddr_in s;
	s.sin_family=AF_INET;
	s.sin_port=3400;
	s.sin_addr.s_addr=INADDR_ANY;
	int c=connect(s2,(struct sockaddr*)&s,sizeof(s));
	printf("Enter message : \n");
	scanf("%s",buf);
	send(s2,buf,sizeof(buf),0);
	recv(s2,buf2,sizeof(buf2),0);
	printf("\n%s\n",buf2);
	close(s2);

}
