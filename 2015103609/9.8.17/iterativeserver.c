#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
int main()
{
int i;
int r,fd;
char buf[2000];
char fname1[20];
struct sockaddr_in nclude<stdio.h>
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
s,t;
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
     
        int a=listen(s1,5);
         

        int e=sizeof(t);
for(i=0;i<3;i++)
{
printf("\nIteration %d",i+1);
printf("\nWaiting on accept");
int c=accept(s1,(struct sockaddr*)&t,&e);
printf("\nAccept ok and successful");
recv(c,buf,sizeof(buf),0);
printf("\nMessage from client:%s",buf);
printf("\nEchoing to client");
send(c,buf,sizeof(buf),0);
close(c);
}
close(s1);
return 0;
}
