#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>
#define MYPORT 3544
struct info{
char url[200];
char version[200];
};
struct resp{
char url[200];
char version[200];
time_t curr;
time_t lastm;

};

main()
{
int len,bytes_sent;
char msg[2000];
int sockfd,new_fd,sin_size;
struct sockaddr_in my_addr;
struct sockaddr_in dest_addr;
if((sockfd = socket(AF_INET, SOCK_STREAM, 0))==-1)
{
printf("Error in creating socket\n");
return 0;
}
my_addr.sin_family = AF_INET;
my_addr.sin_port = htons(MYPORT);
my_addr.sin_addr.s_addr = INADDR_ANY;
if((connect(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)))==-1)
{
printf("Error in connecting\n");
return 0;
}

struct info s1;
printf("Enter url :");
gets(s1.url);
printf("Enter version :");
gets(s1.version);
send(sockfd,(struct info *)&s1,sizeof(struct info),0);
printf("Message Sent \n");

recv(sockfd,msg,sizeof(msg),0);
printf("Message :\n ");
puts(msg);
struct resp a1;
recv(sockfd,(struct resp *)&a1,sizeof(struct resp),0);
printf("Response Message : \n");
printf("URL : %s \n",a1.url);
printf("Version : %s \n",a1.version);
printf("System Time:         %s", ctime(&a1.curr));
printf("Last file modification:   %s", ctime(&a1.lastm));

//struct info s2;

//recv(sockfd,(struct info *)&s2,sizeof(struct info),0);
//printf("The message received \n");
//printf("Url : %s \n",s2.url);
//printf("Version : %s \n",s2.version);


return 0;
}
