#include<bits/stdc++.h>

using namespace std;


int partition(int a[],int n,int l,int r)
{
	int pivot=a[r];
	int i=l-1;
	int j;
	for(j=l;j<=r;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(a[i],a[j]);
			
		}
	}
	return i-1;
}


void sort(int a[],int n,int l,int r)
{
	if(l<r)
	{
		int pm=partition(a,n,l,r);
		sort(a,n,l,pm-1);
		sort(a,n,pm+1,r);
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	
	int i,j,temp,x;
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	sort(a,n,0,n-1);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
