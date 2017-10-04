#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#define MYPORT 1313
#define BACKLOG 20
int main()
{
	int sockfd,newfd,sin_size;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;

	sockfd = socket (AF_INET,SOCK_STREAM,0);
	printf("%d\n",sockfd);
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(MYPORT);
	my_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	if(connect(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1)
		printf("Connect Error");
	else
		printf("Connect Success\n");
	int arr[10],dum[10];
	int buf = 10,i=0;
	int ack=0,temp,lrecv,count=0,k=0,m=3,n=3;
	char msg[100];
	strcpy(msg,"hello");
	send(sockfd,msg,strlen(msg),0);
	printf("\nReading Speed : 3 \n");
	while(1){
		if(temp >= buf){
			if(temp >10 )
				printf("\nRecieved  :  %d \n",temp);
			if(temp>buf){
				m=3;
				while(m){
					dum[k] = arr[k];
					printf("\nArray : %d\n",dum[k]);
					k++;m--;
				}
				send(sockfd,&n,sizeof(n),0);

			}
		}   
		else
		{                                                                                  
			recv(sockfd,&temp,sizeof(temp),0);
			count++;
			if(temp >10 )
				printf("\nRecieved  :  %d \n",temp);
			if(temp>buf){
				m=3;
				while(m){
					dum[k] = arr[k];
					printf("\nArray : %d\n",dum[k]);
					k++;m--;
				}
				send(sockfd,&n,sizeof(n),0);
			}
			else{
				i = (temp-1)%10;
				arr[i]=temp;
				if(ack+1 == temp) 
					ack = temp;
				else
					lrecv = temp;
				if(count!=lrecv)
					send(sockfd,&ack,sizeof(ack),0);
				else
					send(sockfd,&lrecv,sizeof(lrecv),0);
				if(ack==20||lrecv==20)
					break;
			}
		}
		close(sockfd);

		return 0;
	}



