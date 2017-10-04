#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<fcntl.h>
#define MYPORT 1313
#define BACKLOG 20
struct node{
	int seq;
        int ack;
};
int main()
{       
	int sockfd,newfd,sin_size;
	char buf[2000];
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	sockfd = socket (AF_INET,SOCK_STREAM,0);
	printf("%d\n",sockfd);
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(MYPORT);
	my_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1)
		printf("Bind Error\n");
	else
		printf("Bind Success\n");
	if (listen(sockfd,BACKLOG)==-1)
		printf("Listen Error\n");
	else
		printf("Listen Success\n");

	sin_size =  sizeof(struct sockaddr*);

	newfd=accept(sockfd,(struct sockaddr*)&their_addr,&sin_size);
         char msg[100];
	int buff = 10;
        int filesize = 20;
   int arr[10],file [20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        int ack=0,temp=0,count=0,i=0,j,k=0,l,a,speed=0;
         recv(newfd,msg,100,0);
         printf("\n%s\n",msg);
        while(1){
 
             for(j=0;j<buff;j++,k++){

                     arr[j]=file[k];

                 }
          a = 0;
                while(i>10){
                   send(newfd,speed,siezof(speed),0);  
                   recv(newfd,&ack,sizeof(ack),0);
                   while(ack){

                             send(newfd,&arr[a],sizeof(a),0);
                               a++;
                        }


                }
                 
                 
                 while(i<10) {
                            temp=ack;
                           if(arr[i]!=3){
                               send(newfd,&arr[i],sizeof(arr[i]),0);
                               recv(newfd,&ack,sizeof(ack),0);
                               if(temp==ack)  
                                    count++;
                               else
                                   count=0;               
                       }
                      if(count == 3){
                                         l=temp+1;                            
                                    send(newfd,&l,sizeof(temp),0);
                                    recv(newfd,&ack,sizeof(ack),0);          
                              }
                           i++;
                 } 
        if(k==20)
          break;    

}
close(newfd);
 return 0;
}
