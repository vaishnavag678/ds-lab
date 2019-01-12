#include<stdio.h>
int ans[1000];
int o;


void mergesort(int wrong[],int k,int correct[],int j)
{
	o=0;
	int p=1,q=1;
	while(p<=k&&q<=j)
	{
		if(wrong[p]<correct[q])
			ans[++o]=wrong[p++];
		else
			ans[++o]=correct[q++];
	}
	while(p<=k)
		ans[++o]=wrong[p++];
	while(q<=j)
		ans[++o]=correct[q++];
}

void insertionsort(int arr[],int n)
{
	int i,j,temp,r;
	for(i=2;i<=n;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=1&&temp<arr[j];j--)
			arr[j+1]=arr[j];
		arr[j+1]=temp;			
	}
}
void cook(int arr[],int n)
{
	int correct[1000];
	int wrong[1000];
	int i,j=0,k=0;
	for(i=1;i<=n;i++)
	{
		if(arr[i]>arr[i+1])
			wrong[++k]=arr[i];
		else
			correct[++j]=arr[i];
	}
	insertionsort(wrong,k);
	mergesort(wrong,k,correct,j);
}

int main()
{
	int i,n;
	scanf("%d",&n);
	int arr[1000];
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	cook(arr,n);
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
