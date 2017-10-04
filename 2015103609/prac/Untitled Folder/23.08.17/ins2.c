#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define HOST_PORT 3333
#define ROOT_PORT 4444
int main(){
        int fd,n,n1;
        char host[1024],ip[1024],file[1024];
        struct sockaddr_in ins,ans;
        fd=socket(AF_INET,SOCK_DGRAM,0);
        if(fd!=0)
                printf("\nsocket connection working\n");
          ins.sin_family=AF_INET;
        ins.sin_port=HOST_PORT;
        ins.sin_addr.s_addr=INADDR_ANY;
        ans.sin_family=AF_INET;
        ans.sin_port=ROOT_PORT;
        ans.sin_addr.s_addr=INADDR_ANY;
  //      bind(fd,(struct sockaddr*)&ins,sizeof(ins));
        n1=sizeof(ans);n=sizeof(ins);
 char c[10],c2[10];

   //     while(1){
                strcpy(ip," ");
                FILE *fp = fopen("inscache.txt","r");
                recvfrom(fd,host,sizeof(host),0,(struct sockaddr*)&ins,&n);
                while(!feof(fp)){

                          int i,j,len = sizeof(host);
                       for(i=4,j=0;i<len;i++,j++){
                                c[j]= host[i];
                   }
                        fscanf(fp,"%s",file);
                 /*       int len2=sizeof(file);
                       for(i= 4,j=0;i<len2;i++,j++){
                                c2[j]=host[i];}
*/
                        if(strcmp(file,c)==0){
                                fscanf(fp,"%s",ip);
                                break;
}
                        
                }
  
   printf("\nIP of .com : %s",ip);

                sendto(fd,host,sizeof(host),0,(struct sockaddr*)&ans,n1);
                recvfrom(fd,ip,sizeof(ip),0,(struct sockaddr*)&ans,&n1);
                if(strcmp(ip,"ERROR : 404 NOT FOUND")==0)
                        {
                            printf("\nIP address not found\n");
                       sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&ins,n);}
 else{
 printf("\nIP address : %s",ip);
            sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&ins,n);
}
          

/*
                if(strcmp(ip,".")==0){
   sendto(fd,host,sizeof(host),0,(struct sockaddr*)&ans,n1);
                        recvfrom(fd,ip,sizeof(ip),0,(struct sockaddr*)&ans,&n1);
                        if(strcmp(ip,"ERROR.404 NOT FOUND")!=0)
                        {
                                fclose(fp);
                                FILE *fp1=fopen("lnscache.txt","r");
                                fputs(host,fp1);
                                putc("\n",fp1);
                                fputs(ip,fp1);
                                putc("\n",fp1);
                                fclose(fp1);
                        }
                }
                else
                        fclose(fp);
                sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&ins,n);
        }
*/
        return 0;
}

