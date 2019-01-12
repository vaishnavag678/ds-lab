#include<bits/stdc++.h>
using namespace std;
int n;

void maxheapify(int a[],int i,int n)
{
	int left=2*i;
	int right=2*i+1;
	
	int largest;
	
	if(left<=n && a[left]>a[i])
	largest=left;
	else
	largest=i;
	
	if(right<=n && a[right]>a[largest])
	largest=right;
	
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		
		maxheapify(a,largest,n);
	}
}

void buildmaxheap(int a[])
{
	for(int i=n/2;i>=1;i--)
	{
		maxheapify(a,i,n);
	}
}
void heapsort(int a[])
{
	int heapsize=n;
	buildmaxheap(a);
	int i;
	for(i=n;i>=2;i--)
	{
		swap(a[1],a[i]);
		heapsize=heapsize-1;
		maxheapify(a,1,heapsize);
	}
	
}

void insert(int a[],int x)
{
	n=n+1;
	a[n]=x;
	//swap(a[1],a[n]);
	maxheapify(a,1,n);
}

int main()
{
	cin>>n;
	int a[n+5];
	int i;
	for(i=1;i<=n;i++)
	cin>>a[i];
	
	heapsort(a);
	for(i=1;i<=n;i++)
	cout<<a[i]<<" ";
	
	int entry;
	cin>>entry;
	insert(a,entry);
	heapsort(a);
	for(i=1;i<=n;i++)
	cout<<a[i]<<" ";
}
