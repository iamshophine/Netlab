#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<fcntl.h>
#define MYPORT 1313
#define BACKLOG 20
#include<time.h>
struct node{
	char method[20];
	char file[100];
        char version [20];
        char user_agent [20];
        char server[20];
        char check[50];
        int userpass[50];
        int length;
        char msg[100];
          
};
struct node2{
char username[20];
char password[20];
};

main()
{
	struct node dd;
        struct node2 up;
        strcpy(dd.version,"HTTP/1.0");
        strcpy(dd.user_agent,"Mozilla/2.0");
        strcpy(dd.server,"Apache server");
	int sockfd,sin_size;
	struct sockaddr_in my_addr;
	char buf2[2000];
	buf2[2000]='\0';
	sockfd = socket (AF_INET,SOCK_STREAM,0);
	printf("%d\n",sockfd);
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(MYPORT);
	my_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	if(connect(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1)
		printf("Connect Error");
	else
		printf("Connect Success\n");

	printf("\nEnter method : get or post\n");
	scanf("%s",dd.method);
 
	if (strcmp(dd.method,"get")==0)
	{      
                 printf("\n Enter File name: \n");
        scanf("%s",dd.file);

         printf("file:%s\n",dd.file);
        send(sockfd,(struct node *)&dd,sizeof(struct node),0);
             recv(sockfd,(struct node *)&dd,sizeof(struct node),0);
                 printf("\nMethod : %s",dd.method);
                    printf("\nVersion : %s",dd.version);
               printf("\nUser : %s",dd.user_agent);
                    printf("\nServer : %s",dd.server);
                  printf("\nDate : ");
                 system("date");
                 char buf3[2000];
        	int a = recv(sockfd,buf2,2000,0);
		printf("\nMessage Recieved\n");
		printf("\n%s\n",buf2);
                 
	}
	else 
	{       
                  printf("\nUsername : ");
                  scanf("%s",up.username);
                  printf("\nPassword : ");
 scanf("%s",up.password);
strcat(up.username,up.password);
int i;
dd.length=0;

for(i=0;i<strlen(up.username);i++)
{

dd.userpass[i]=up.username[i];
dd.length++;
}
printf("\nChecking....\n");
send(sockfd,(struct node *)&dd,sizeof(struct node),0);
recv(sockfd,(struct node *)&dd,sizeof(struct node),0);
 printf("\nMethod : %s",dd.method);
                    printf("\nVersion : %s",dd.version);
               printf("\nUser : %s",dd.user_agent);
                    printf("\nServer : %s",dd.server);
                  printf("\nDate : ");
                  system("date");

printf("\n%s",dd.msg);
}
}

