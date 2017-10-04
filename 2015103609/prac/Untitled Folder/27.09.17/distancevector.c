#include<stdio.h>
struct node
{
	unsigned dist[20];
	unsigned from[20];
}rt[10];
int main()
{
	int costmat[20][20];
	int nodes,i,j,k,m,x,count=0;
	printf("\nEnter no. of nodes : ");
	scanf("%d",&nodes);
	printf("\nEnter cost matrix : \n");
	for(i=0;i<nodes;i++)
	{	for(j=0;j<nodes;j++)
		{
			scanf("%d",&costmat[i][j]);
			if(costmat[i][j]==0)
				if(i==j)
					costmat[i][j]=0;
				else
					costmat[i][j]=999999;

			rt[i].dist[j]=costmat[i][j];
			rt[i].from[j]=j;
		 }
                        printf("\nMap of %d : \n",i+1);
                   for(x=0;x<nodes;x++){
                            printf("%d to %d  : %d \n" ,i+1,x+1,costmat[i][x]);             
                       }
		}
                
	do
	{
		count=0;
		for(i=0;i<nodes;i++)
			for(j=0;j<nodes;j++)
				for(k=0;k<nodes;k++)
					if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
					{
						rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
						rt[i].from[j]=k;
						count++;
						if(i==0&&j==4)
							printf("distance : %d from : %d\n",rt[i].dist[j],rt[i].from[j]);
					}
	}
	while(count!=0);
	for(i=0;i<nodes;i++)
	{
		printf("\nFor router %d",i+1);
		for(j=0;j<nodes;j++)
			printf("\nnode %d\tvia %d\tdistance %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
	}
	return 0;
}


