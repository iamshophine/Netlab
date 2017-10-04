#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#define PORT 6969
int main()
{
        int sock,bytes_received,connected,true=1,i=1,f=0,sin_size;
        char send_data[1024],data[1024],fr[30]=" ";
        struct sockaddr_in s,c;
        if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
        {
                perror("Socket not created\n");
                exit(1);
        }
        if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&true,sizeof(int))==-1)
        {
                perror("Setsockopt error\n");
                exit(1);
        }
        s.sin_family=AF_INET;
        s.sin_port=htons(PORT);
        s.sin_addr.s_addr=htons(INADDR_ANY);
        if(bind(sock,(struct sockaddr*)&s,sizeof(struct sockaddr))==-1)
        {
                perror("Bind failed\n");
                exit(1);
        }
        sin_size=sizeof(struct sockaddr_in);
        connected=accept(sock,(struct sockaddr*)&c,&sin_size);
        while(strcmp(fr,"exit")!=0)
        {
                printf("Enter data frame %d : (Enter exit to end):",i);
                scanf("%[^\n]",fr);
                getchar();
                send(connected,fr,strlen(fr),0);
                memset(data,0,sizeof data);
                recv(connected,data,1024,0);
                if(strlen(data)!=0)
                        printf("I got an acknowledgement : %s\n",data);
                i++;
        }
        close(sock);
        return(0);
}

