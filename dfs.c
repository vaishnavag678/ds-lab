#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int adj[10][10]={0};
int visited[10]={0};

void dfs(int row)
{
	visited[row]=1;
	printf("%d ",row);
	int j;
	
	for(j=0;j<10;j++)
	{
		if(visited[j]==0&&adj[row][j]==1)
		{
		//	printf("vaishnav \n");
			dfs(j);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int i;
	int x,y,head;
//	printf("enter the head ");
//	scanf("%d",&head);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		adj[x][y]=1;
		adj[y][x]=1;
	}
	printf("enter the head ");
	scanf("%d",&head);
	dfs(head);
	
}
