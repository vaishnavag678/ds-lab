#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE
{
	int weight;
	int first;
	int sec;
};
typedef struct NODE N;

int nodes,edges;

N arr[100005];
int id[100005];


void initialize()
{	
	int i;
	for(i=0;i<100005;i++)
	id[i]=i;
}
int root(int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void uni(int z,int y)
{
	int p=root(z);
	int q=root(y);
	id[p]=id[q];
}
void sort(N a[])
{
	int i,j;	
	for(i=0;i<edges-1;i++)
	{
		for(j=0;j<edges-i-1;j++)
		{
			if(a[j].weight>a[j+1].weight)
			{
				int temp=a[j].weight;
				a[j].weight=a[j+1].weight;
				a[j+1].weight=temp;
			}
		}
	}
}
int algo(N a[])
{
	int x,y,cost;
	int mincost=0;
	int i;
	for(i=0;i<edges;i++)
	{
		x=a[i].first;
		y=a[i].sec;
		cost=a[i].weight;
		
		if(root(x)!=root(y))
		{
			mincost=mincost+cost;
			uni(x,y);
		}
		
	}
	return mincost;
}
int main()
{
	printf("enter the number of nodes and edges ");
	scanf("%d%d",&nodes,&edges);
	int i;
	int x,y,w;
	initialize();
	printf("enter weight of edge from x to y \n");
	for(i=0;i<edges;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		arr[i].weight=x;
		arr[i].first=y;
		arr[i].sec=w;
		
	}
	sort(arr);
	printf("%d",algo(arr));
	
}

