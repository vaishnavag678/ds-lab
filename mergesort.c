#include<stdio.h>
#include<stdlib.h>


void merge(int a[],int l,int mid,int r)
{
	int ln=mid-l+1;
	int rn=r-mid,i;
	
	int left[ln],right[rn];
	
	for(i=0;i<ln;i++)
	left[i]=a[l+i];
	
	for(i=0;i<rn;i++)
	right[i]=a[mid+1+i];
	int j,k;
	i=0;
	j=0;
	k=0;
	while(i<ln&&j<rn)
	{
		if(left[i]<right[i])
		{
			a[l+k]=left[i];
			i++;
			k++;
		}
		else 
		{
			a[l+k]=right[j];
			j++;
			k++;
		}
	}
	while(i<ln)
	{
		a[k+l]=left[i];
		k++;
		i++;
	}
	while(j<rn)
	{
		a[k+l]=right[j];
		k++;
		j++;
	}
}

void sort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		
		sort(a,l,mid);
		sort(a,mid+1,r);
		
		merge(a,l,mid,r);
	}
//	printf("vaishnav");
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,x;
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	sort(a,0,n-1);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
