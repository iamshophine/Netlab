#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
int main()
{

int r,fd;
char buf[2000];
char fname1[20];
struct sockaddr_in s,t;
char *path;
        int s1=socket(AF_INET,SOCK_STREAM,0);
        if(s1==-1)
        {
                printf("socket not created");
        }
        s.sin_family=AF_INET;
        s.sin_port=3400;
        s.sin_addr.s_addr=INADDR_ANY;
        int b=bind(s1,(struct sockaddr*)&s,sizeof(s));
        printf("\n socket descriptor%d\n",s1);
        printf("bind %d\n",b);
        int a=listen(s1,5);
         printf("%d\n",a);

        int e=sizeof(t);
        int c=accept(s1,(struct sockaddr*)&t,&e);
        path="sf32@sfdc.audcse@lsf-c06/02-08-2017/dir";
        chdir(path);
        recv(c,fname1,100,0);
        printf("\n file name received:%s",fname1);
        fd=open(fname1,0);
    if(fd==-1)
    printf("error");
r=read(fd,buf,sizeof(buf));
send(c,buf,strlen(buf),0);
        return 0;
}

