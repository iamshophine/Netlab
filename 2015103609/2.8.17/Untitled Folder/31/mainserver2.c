#include<stdio.h>
#include<sys/types.h>
#include<errno.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

struct format{char method[20];
char version[20];
char url[20];
char body[2000];
int flag;
time_t ti;} td;

void main()
{
int gf,ds,l,g,i;
int size;
int yes=1;
char mgs[50];
struct sockaddr_in myadd,tdd;
gf=socket(AF_INET,SOCK_STREAM,0);
printf("%d\n",gf);
myadd.sin_family=AF_INET;
myadd.sin_port=htons(5517);
myadd.sin_addr.s_addr=INADDR_ANY;
ds=bind(gf,(struct sockaddr *) &myadd,sizeof(struct sockaddr));
printf("%d\n",ds);
l=listen(gf,5);
printf("%d\n",l);
size=sizeof(struct sockaddr_in);
g=accept(gf,(struct sockaddr *)&tdd,&size);
if(g!=-1)
printf("\nconnected to the client");
recv(g,&td,sizeof(td),0);




struct stat sb;
lstat(td.url,&sb);
if((td.ti==0)||(sb.st_mtime>td.ti))
{strcpy(td.method,"got");
int fp=open(td.url,0,O_RDONLY);
read(fp,td.body,50);
}else{td.flag=0;}
td.flag=1;
send(g,&td,sizeof(td),0);







}





