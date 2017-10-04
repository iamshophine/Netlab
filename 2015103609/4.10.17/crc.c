#include<stdio.h>
#define N strlen(g)
char t[28],cs[28],g[]="1000100000100001";
int a,e,c;
int main()
{
	
	return 0;
}
void xor()
{
	for(c=1;c<N;c++)
		cs[c]=(cs[c]==g[c]?'0':'1');
}
void crc()
{
	for(e=0;e<N;e++)
		cs[e]=t[e];
	do{
		if(cs[0]=='1')
			xor();
		for(c=0;c<N-1;c++)
			cs[c]=cs[c+1];
		cs[c]=t[c++];
	}while(e<=(a+N-1);
}
int main()
{
	printf("\nEnter data : ");
	scanf("%s",t);
	printf("\nEnter the generating polynomial : ");
	a=strlen(t);
	for(e=a;e<(a+N-1);e++)
		t[e]=cs[e-a];
	printf("\nFinal codeword : %s",t);
	printf("\nTest error detection\n\nYes-->0\nNo-->1 :");
	scanf("%d",&e);
	if(e==0){
		do{	
			printf("\nEnter the position where the error is to be inserted :");
			scanf("%d",&e);
		}while(e==0||e>(a+N-1));
			
	return 0;
}
