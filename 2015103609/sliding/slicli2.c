#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
int main()
{
        struct sockaddr_in serv_addr;
        int c,i,j,sockfd,ts,size;
        j=0;
        char buffer[1024],choice[10],data[5][100];
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_addr.s_addr=INADDR_ANY;
        serv_addr.sin_port=htons(3344);
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd>=0)
                printf("\nSocket created\n");
        printf("%d",sockfd);
        c=connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
        if(c>=0)
                printf("\nConnected\n");
        printf("Please enter receive window size : \n");
        scanf("%d",&size);
        send(sockfd,&size,sizeof(size),0);
        sleep(5);
        recv(sockfd,&ts,sizeof(ts),0);
        printf("The total iterations needed : %d\n",ts);
        while(1)
        {
                sleep(5);
                recv(sockfd,buffer,1024,0);
                if(strcmp(buffer,"exit")==0)
                {
                        close(sockfd);
                        break;
                }
                printf("\n[%d] The recieved frame is %s\n",i+1,buffer);
                strcpy(data[j],buffer);
                printf("\ndo you want to ack it?\n");
                scanf("%s",choice);
                send(sockfd,choice,sizeof(choice),0);
                sleep(2);
	        printf("Have you read it?\n");
                scanf("%s",choice);
                send(sockfd,choice,sizeof(choice),0);
                if(strcmp(choice,"read")==0)
                {
                        i++;
                }
                else{
                        printf("Enter yes when done reading\n");
                        scanf("%s",buffer);
                        send(sockfd,buffer,sizeof(buffer),0);
                        i++;
                }
                if(i==ts)
                {
                        printf("Finisht Reading\n");
                        exit(1);
                }
        }
        close(sockfd);
}

