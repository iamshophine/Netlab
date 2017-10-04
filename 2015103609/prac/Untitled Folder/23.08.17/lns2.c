#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define HOST_PORT 1234
#define ROOT_PORT 2222
int main(){
        int fd,n,n1;
        char host[1024],ip[1024],file[1024];
        struct sockaddr_in lns,rns;
        fd=socket(AF_INET,SOCK_DGRAM,0);
        if(fd!=0)
                printf("\nsocket connection working\n");
        lns.sin_family=AF_INET;
        lns.sin_port= HOST_PORT;
        lns.sin_addr.s_addr=INADDR_ANY;
        rns.sin_family=AF_INET;
        rns.sin_port=ROOT_PORT;
        rns.sin_addr.s_addr=INADDR_ANY;
       // bind(fd,(struct sockaddr*)&lns,sizeof(lns));
        n1=sizeof(rns);n=sizeof(lns);
      //  while(1){
      //        strcpy(ip," ");
      //        FILE *fp = fopen("lnscache.txt","r");
           recvfrom(fd,host,sizeof(host),0,(struct sockaddr*)&lns,&n);
            printf("\n%s\n",host);
          /*      while(!feof(fp)){

                        fscanf(fp,"%s",file);
                        if(strcmp(file,host)==0){
                               fscanf(fp,"%s",ip);
                              break;
}
                        
                }
                if(strcmp(ip,".")==0){   */
      printf("\nHost name : %s",host);
   sendto(fd,host,sizeof(host),0,(struct sockaddr*)&rns,n1);
   recvfrom(fd,ip,sizeof(ip),0,(struct sockaddr*)&rns,&n1);
                        if(strcmp(ip,"ERROR : 404 NOT FOUND")==0)
                        {
                            printf("\nIP address not found\n");
                       sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&lns,n);}
 else{           
 printf("\nIP address : %s",ip);
            sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&lns,n);
}
                       /*        fclose(fp);
                              FILE *fp1=fopen("lnscache.txt","a");
                                fputs(host,fp1);
                                putc('\n',fp1);
                                fputs(ip,fp1);
                                putc('\n',fp1);
                                fclose(fp1);
  
                        }

                }
                else
                        fclose(fp);
    i            sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&lns,n);
        P of .com : %s".ip);

                sendto(fd,host,sizeof(host),0,(struct sockaddr*)&ins,n1);
                recvfrom(fd,ip,sizeof(ip),0,(struct sockaddr*)&ins,&n1);
                if(strcmp(ip,"ERROR : 404 NOT FOUND")==0)
                        {
                            printf("\nIP address not found\n");
                       sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&lns,n);}
 else{
 printf("\nIP address : %s",ip);
            sendto(fd,ip,sizeof(ip),0,(struct sockaddr*)&lns,n);
}
}*/
        return 0;
}

