#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#define MYPORT 3550
#define BACKLOG 10 
struct info{
char url[200];
char version[200];
char method[200];
};

struct resp{
char url[200];
char version[200];
time_t curr;
time_t lastm;

};


int main()
{
int len,bytes_sent;
char msg[2000];
char msg1[2000];

int sockfd,new_fd,sin_size;
struct sockaddr_in addr;
struct sockaddr_in their_addr;
if((sockfd = socket(AF_INET, SOCK_STREAM, 0))==-1)
{
printf("Error in creating socket\n");
return 0;
}
addr.sin_family = AF_INET;
addr.sin_port = htons(MYPORT);
addr.sin_addr.s_addr=INADDR_ANY;
memset(&(addr.sin_zero), '\0', 8);
if( (len = bind(sockfd,(struct sockaddr *)&addr,sizeof(struct sockaddr)))==-1)
{
perror("bind");
printf(" error in binding\n");
return 0;
}
if((listen(sockfd, BACKLOG))==-1)
{
printf("Error in listening\n");
return 0;
}
sin_size = sizeof(struct sockaddr_in);
new_fd = accept(sockfd, (struct sockaddr *) &their_addr, &sin_size);
if(new_fd==-1)
{
printf("Error in accepting\n");
return 0;
}

struct info s2;

recv(new_fd,(struct info *)&s2,sizeof(struct info),0);
printf("The message received \n");
printf("Url : %s \n",s2.url);
printf("Version : %s \n",s2.version);

int fd;
//char *a="/home/sf32@sfdc.audcse/3545";
//strcat(a,s2.url);
//puts(s2.url);

fd=open(s2.url,O_RDONLY);
read(fd,msg,2000);
puts(msg);
send(new_fd,msg,sizeof(msg),0);
printf("Message Sent ");
struct resp a1;

time(&(a1.curr));
struct stat sb;
stat(s2.url, &sb);

a1.lastm=sb.st_mtime;
strcpy(a1.url,s2.url);
strcpy(a1.version,s2.version);
//printf("Last file modification:   %s", a1.url);

send(new_fd,(struct resp *)&a1,sizeof(struct resp),0);
printf("Response Message sent : \n");
//puts(msg);

//printf("Enter url :");
//gets(s1.url);
//printf("Enter version :");
//gets(s1.version);

//send(new_fd,(struct info *)&s1,sizeof(struct info),0);
//printf("Message Sent ");

return 0;
}    
