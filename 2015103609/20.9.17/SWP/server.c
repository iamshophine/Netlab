#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
int main()
{
int index[100],k,a,b,c,window_size,sockfd,newsockfd,i=1,j=0,clilen,ack;
struct sockaddr_in serv_addr,cli_addr;
char buffer[1024],data[10][100],ch[10][1000];
printf("\nEnter the window size\n");
scanf("%d",&window_size);
printf("\nEnter the data for 10 elements\n");
for(i=0;i<10;i++)
scanf("%s",data[i]);
serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(3978);
serv_addr.sin_addr.s_addr=INADDR_ANY;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd>=0)
printf("\nSocket created\n");
printf("%d",sockfd);
b=bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
if(b>=0)
printf("\nBinded\n");
printf("%d",b);
a=listen(sockfd,5);
if(a>=0)
printf("\nListening\n");
printf("%d",a);
printf("\nServer:Waiting for client\n");
clilen=sizeof(clilen);
newsockfd=accept(sockfd,(struct sockaddr *)&serv_addr,&clilen);
if(10%window_size==0)
k=10/window_size;
else
k=10/window_size+1;
send(newsockfd,&window_size,sizeof(window_size),0);
while(j<k)
{
for(i=0;i<window_size;i++)
{
printf("\nEnter the index to send\n");
scanf("%d",&index[i]);
printf("\n[%d] packet being transmitted is %s\n",index[i],data[index[i]]);
strcpy(ch[i],data[index[i]]);
printf("\nChoice is %s",ch[i]);
}
send(newsockfd,index,sizeof(index),0);
send(newsockfd,ch,sizeof(ch),0);
recv(newsockfd,&ack,sizeof(ack),0);
printf("\nacknowledgement Recvied at %d\n",ack);
j++;
}
close(sockfd);
return 0;
}

