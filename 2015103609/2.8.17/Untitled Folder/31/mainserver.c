#include<stdio.h>
#include<sys/types.h>
#include<errno.h>


#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
struct format{char method[20];
char version[20];
char url[30];
char body[200];
}dt;

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
myadd.sin_port=htons(6572);
myadd.sin_addr.s_addr=INADDR_ANY;
ds=bind(gf,(struct sockaddr *) &myadd,sizeof(struct sockaddr));
printf("%d\n",ds);
l=listen(gf,5);
printf("%d\n",l);
size=sizeof(struct sockaddr_in);
g=accept(gf,(struct sockaddr *)&tdd,&size);
if(g!=-1)
printf("\nconnected to the client");
recv(g,&dt,sizeof(dt),0);


int xd=open(dt.url,0,O_RDONLY);



if(strcmp(dt.method,"get")==0)
{
if(read(xd,dt.body,50)==-1)
{strcpy(dt.body,"URL not found");}
}
else if(strcmp(dt.method,"post")==0)
{for( i=0;i<strlen(dt.body);i++)
{if(dt.body[i]>=65&&dt.body[i]<97){dt.body[i]+=32;}

else if(dt.body[i]>=97){dt.body[i]-=32;}
}




}
send(g,&dt,sizeof(dt),0);
close(xd);
}

