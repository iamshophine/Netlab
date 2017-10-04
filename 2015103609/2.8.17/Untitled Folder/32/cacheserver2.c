#include<stdio.h>
#include<sys/types.h>
#include<errno.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

struct format{char method[20];
char version[20];
char url[20];
char body[2000];
int flag;
time_t ti;}td;


void main()
{
int gf,ds,l,g,i;
int size;
int yes=1;
char mgs[50];
struct sockaddr_in myadd,tdd,mserv;
gf=socket(AF_INET,SOCK_STREAM,0);
int b=socket(AF_INET,SOCK_STREAM,0);

printf("%d\n%d\n",gf,b);
myadd.sin_family=AF_INET;
myadd.sin_port=htons(5417);
myadd.sin_addr.s_addr=INADDR_ANY;
ds=bind(gf,(struct sockaddr *) &myadd,sizeof(struct sockaddr));
mserv.sin_family=AF_INET;
mserv.sin_port=htons(5517);
mserv.sin_addr.s_addr=INADDR_ANY;
printf("\n%d\n",connect(b,(struct sockaddr *)&mserv,sizeof(struct sockaddr)));

printf("%d\n",ds);
l=listen(gf,5);
printf("%d\n",l);
size=sizeof(struct sockaddr_in);
g=accept(gf,(struct sockaddr *)&tdd,&size);
if(g!=-1)
printf("\nconnected to the client");
recv(g,&td,sizeof(td),0);


struct stat sb;
int x=lstat(td.url,&sb);
if(x!=-1)
{td.ti=sb.st_mtime;
}
send(b,&td,sizeof(td),0);
recv(b,&td,sizeof(td),0);
if(strcmp(td.method,"got")!=0)
{int x=open(td.url,0,O_RDONLY);
read(x,td.body,200);
}
else{printf("\nfromms");
int fd=open(td.url,O_CREAT|O_RDWR,0666);
write(fd,td.body,strlen(td.body));
printf("\nfromms");

}
send(g,&td,sizeof(td),0);


}








 
