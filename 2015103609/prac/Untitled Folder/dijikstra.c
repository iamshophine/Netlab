#include<stdio.h>
#define MAX 10
#define INFINITY 9999
void dijikstra(int g[MAX][MAX],int n,int startnode);
int main()
{
	int g[MAX][MAX],i,j,n,u;
	printf("\n Enter the number of nodes: \n");
	scanf("%d",&n);
	printf("\n Enter cost matrix :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	printf("\n Enter starting node ");
	scanf("%d",&u);
	dijikstra(g,n,u);
	return 0;
}
void dijikstra(int g[MAX][MAX],int n,int startnode)
{
	int cost[MAX][MAX],distance[MAX],pred[MAX],visited[MAX],count,mindist,nextnode,i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(g[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=g[i][j];
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindist=INFINITY;
		for(i=0;i<n;i++)
		{
			if(distance[i]<mindist && !visited[i])
			{
				mindist=distance[i];
				nextnode=i;
			}
		}
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				if((mindist+cost[nextnode][i]) < distance[i])
				{
					distance[i] = mindist+cost[nextnode][i];
					pred[i]=nextnode;
				}
			}
		
		}
		count++;
	}
	for(i=0;i<n;i++)
	{
		if(i!=startnode)
		{
			printf("\n Distance of %d from %d = %d " ,i,startnode,distance[i]);
			printf("\n Path : ");
			printf("%d",i);
			j=i;
			do
			{
				j=pred[j];
				printf("<---%d",j);
			}while(j!=startnode);
		}
        printf("\n");
	}
}
