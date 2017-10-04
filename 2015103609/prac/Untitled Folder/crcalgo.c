#include<stdio.h>
int main()
{
	int i,j,k,l;
	int fs;
	printf("\nEnter the data size : ");
	scanf("%d",&fs);
  
	int f[20];
	printf("\nEnter the data : ");
	for(i=0;i<fs;i++)
		scanf("%d",&f[i]);

	int gs;
	printf("\nEnter generator size : ");
	scanf("%d",&gs);

	int g[20];
	printf("\nEnter generator : ");
	for(i=0;i<gs;i++)
		scanf("%d",&g[i]);

	printf("\nSender Size: \nFrame");
	for(i=0;i<fs;i++)
		printf("%d",f[i]);
	printf("\nGenerator : ");
	for(i=0;i<gs;i++)
		printf("%d",g[i]);
	
   	int rs=gs-1;
	printf("\nNumber of zeros to be appended %d",rs);
	for(i=fs;i<fs+rs;i++)
		f[i]=0;
	int temp[20];
	for(i=0;i<20;i++)
		temp[i]=f[i];
	printf("\nMessage after appending zeros");
	for(i=0;i<fs+rs;i++)
		printf("%d",temp[i]);
	for(i=0;i<fs;i++)
	{
		j=0;
		k=i;
		if(temp[k]>=g[j])
		{
			for(j=0,k=i;j<gs;j++,k++)
			{ 
				if((temp[k]==1 && g[j]==1)||(temp[k]==0 && g[j]==0))
					temp[k]=0;
				else
					temp[k]=1;
			}
		}
	}
	int crc[15];
	for(i=0,j=fs;i<rs;i++,j++)
		crc[i]=temp[j];
	printf("\nCyclic Redundency Check Bits : ");
	for(i=0;i<rs;i++)
		printf("%d",crc[i]);
	printf("\nTransmitted Frame ");
	int tf[15];
	for(i=0;i<fs;i++)
		tf[i]=f[i];
	for(i=fs,j=0;i<fs+rs;i++,j++)
		tf[i]=crc[j];
	for(i=0;i<fs+rs;i++)
		printf("%d",tf[i]);

	printf("\nReceiver side: ");
	printf("\nReceiver frame: ");
	for(i=0;i<fs+rs;i++)
		printf("%d",tf[i]);
	for(i=0;i<fs+rs;i++);
	temp[i]=tf[i];
	for(i=0;i<fs+rs;i++)
	{
		j=0;
		k=i;
		if(temp[k]>=g[j])
		{
			for(j=0,k=i;j<gs;j++,k++)
			{ 
				if((temp[k]==1 && g[j]==1)||(temp[k]==0 && g[j]==0))
					temp[k]=0;
				else
					temp[k]=1;
			}
		}
	}
	printf("\nRemainder : ");
	int rrem[15];
	for(i=fs,j=0;i<fs+rs;i++,j++)
		rrem[j]=temp[i];
	for(i=0;i<rs;i++)
		printf("%d",rrem[i]);
	int flag=0;
	for(i=0;i<rs;i++)
		if(rrem[i]!=0)
			flag=1;
	if(flag==0)
		printf("\nSince remainder is 0,message transmitted from sender to receiver is correct");
	else
		printf("\nSince remainder is 1,message contains error");
	return 0;
}
