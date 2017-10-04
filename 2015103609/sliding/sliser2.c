#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
int main()
{
        int a,t,b,c,window_size,sockfd,newsockfd,i=1,j=0,clilen;
        struct sockaddr_in serv_addr,cli_addr;
        char buffer[1024],data[10][100];
        printf("Send window size is 10\n");
        printf("\nEnter the data for 10 elements\n");
        for(i=0;i<10;i++)
                scanf("%s",data[i]);
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_port=htons(3344);
        serv_addr.sin_addr.s_addr=INADDR_ANY;
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd>=0)
                printf("\nSocket created\n");
        printf("%d",sockfd);
        b=bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
        if(b>=0)
                printf("\nBinded\n");
        printf("\nBindind error %d",b); 
        a=listen(sockfd,5);
        if(a>=0)
                printf("\nListening\n");
        printf("%d",a);
        printf("\nServer:Waiting for client\n");
        clilen=sizeof(clilen);
        newsockfd=accept(sockfd,(struct sockaddr *)&serv_addr,&clilen);
        printf("Waiting to receive receive window size\n");
        sleep(5);
        recv(newsockfd,&window_size,sizeof(window_size),0);
        printf("Receive window size : %d",window_size);
        t=10/window_size;
        send(newsockfd,&t,sizeof(t),0);
        sleep(10);
        while(j<10/window_size)
        {
retransmit:
                for(i=(j*window_size);i<((j+1)*window_size);i++)
                {
                        printf("\n[%d] packet being transmitted is %s\n",i,data[i]);
                        send(newsockfd,data[i],strlen(data[i]),0);
                }
                sleep(5);
                recv(newsockfd,buffer,1024,0);
                printf("\nRecv%s\n",buffer);
                if(strcmp(buffer,"ack")!=0)
                        goto retransmit;
                else{
                        recv(newsockfd,buffer,1024,0);
                        if(strcmp(buffer,"read")==0)
                                j++;
                        else
                        {
                                printf("Waiting for host to read\n");
                                recv(newsockfd,buffer,1024,0);
                                printf("User read\n");
                                j++;
                        }
                }
        }
        close(sockfd);
        return 0;
}

