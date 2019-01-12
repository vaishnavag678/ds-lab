#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int n,int i)
{
	int largest=i;
	
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n&&a[l]>=a[largest])
		largest=l;
	if(r<n && a[r]>=a[largest])	
		largest=r;
		
	if(largest!=i)
	{
		swap(a[largest],a[i]);
		heapify(a,n,largest);
	}
}
void heapsort(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	heapify(a,n,i);
	
	for(i=n-1;i>=0;i--)
	{
		swap(a[i],a[0]);
		heapify(a,i,0);
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
	heapsort(a,n);
//	heapify(a,n,0);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
