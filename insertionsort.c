#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int i,j,temp,x;
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=1;i<n;i++)
	{
		temp=a[i];
		
		for(j=i-1;j>=0&&temp<a[j];j--)
		{
			x=a[j];
			a[j]=a[j+1];
			a[j+1]=x;
		}	
		a[j+1]=temp;
	}
	for(i=0;i<n;i++)printf("%d ",a[i]);
}

 
