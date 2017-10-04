#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
int main()
{
struct sockaddr_in serv_addr;
int k,window_size,a,c,i,sockfd,j=0,index[100];
char buf1[10][1000],choice[10],ack[10][100];
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(3978);
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd>=0)
printf("\nSocket created\n");
printf("%d",sockfd);
c=connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
if(c>=0)
printf("\nConnected\n");
printf("%d",c);
for(i=0;i<100;i++)
strcpy(ack[i],"noack");
recv(sockfd,&window_size,sizeof(window_size),0);
printf("\nThe window size is %d\n",window_size);
if((10%window_size)==0)
k=10/window_size;
else
k=10/window_size+1;
while(j<k)
{
recv(sockfd,index,sizeof(index),0);
recv(sockfd,buf1,sizeof(buf1),0);
for(i=0;i<window_size;i++)
{
printf("%s value",buf1[i]);
printf("\n[%d] The recieved frame is %s\n",index[i],buf1[i]);
strcpy(ack[index[i]],"ack");
}
for(i=0;i<100;i++)
{
if(strcmp(ack[i],"noack")==0)
break;
}
printf("\n ack %d",i);
a=(i-1);
printf("\nack1 %d",a);
send(sockfd,&a,sizeof(a),0);
j++;
}
close(sockfd);
}
