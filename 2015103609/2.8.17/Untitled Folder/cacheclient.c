#include<stdio.h>
#include<sys/types.h>
#include<errno.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
struct format{char method[20];
char version[20];
char url[20];
char body[2000];
int flag;
time_t ti;}dt;

void main()
{int a,b,c;
struct sockaddr_in tff;
 a=socket(AF_INET,SOCK_STREAM,0);
printf("\n%d",a);
tff.sin_family=AF_INET;
tff.sin_port=htons(5417);
tff.sin_addr.s_addr=INADDR_ANY;
b=connect(a,(struct sockaddr *)&tff,sizeof(struct sockaddr));
printf("\n%d",b);
printf("\nenter method  ");
scanf("%s",dt.method);
printf("\nenter version  ");
scanf("%s",dt.version);
printf("\nenter url   ");
scanf("%s",dt.url);
send(a,&dt,sizeof(dt),0);
recv(a,&dt,sizeof(dt),0);
printf("\n%s",dt.body);

printf("\n%s",dt.method);


}
