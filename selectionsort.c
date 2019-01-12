#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int i,j,current,x;
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	
	for(i=0;i<n-1;i++)
	{
		 current=i;
		
		for(j=current+1;j<n;j++)
		{
			if(a[current]>a[j])	
			current=j;
			
		}
		x=a[current];
		a[current]=a[i];
		a[i]=x;
	}
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
}
