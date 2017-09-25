#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define LNS 2222
int main(){

	int sd1,i,j;        
	char host[1024],ip[1024],file[2000],c[10];
	struct sockaddr_in rns;
	int len1=sizeof(rns);
	sd1=socket(AF_INET,SOCK_DGRAM,0);
	rns.sin_family=AF_INET;
	rns.sin_port= LNS ;
	rns.sin_addr.s_addr=INADDR_ANY;

	bind(sd1,(struct sockaddr *)&rns,len1);
	while(1){
int n=recvfrom(sd1,host,sizeof(host),0,(struct sockaddr *)&rns,&len1);
		
host[n]='\0';

if(n<0)
			printf("\nError in recv\n");

		printf("\nHostname : %s\n",host);

		int flag=rand()%3;
		int len=strlen(host);
		for(i=len-3,j=0;i<len;i++,j++)
		{
			c[j]=host[i];
		}
		if(flag==0){


			FILE *fp=fopen("rns1.txt","r");
			printf("\nFILE 1\n");
			while(!feof(fp)){

				fscanf(fp,"%s",file);
				if(strcmp(c,file)==0){
					fscanf(fp,"%s",ip);
					break;
				}

			}
		}
		else if (flag==1){

			FILE *fp=fopen("rns2.txt","r");
			printf("\nFILE 2\n");

			while(!feof(fp)){

				fscanf(fp,"%s",file);
				if(strcmp(c,file)==0){
					fscanf(fp,"%s",ip);
					break;
				}

			}

		}
                else if (flag==2){

                        FILE *fp=fopen("rns3.txt","r");
                        printf("\nFILE 3\n");

                        while(!feof(fp)){

                                fscanf(fp,"%s",file);
                                if(strcmp(c,file)==0){
                                        fscanf(fp,"%s",ip);
                                        break;
                                }

                        }

                }

		if(ip[0]=='\0')
			strcpy(ip,"ERROR : 404 NOT FOUND");
		printf("\nIP of .%s in TLD : %s\n",c,ip);
       sendto(sd1,ip,strlen(ip),0,(struct sockaddr *)&rns,len1);
		strcpy(ip,"");
		strcpy(host,"");
	}
	return 0;
}
