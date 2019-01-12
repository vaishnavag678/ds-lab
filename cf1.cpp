#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[1005];
	int i;
	for(i=1;i<=n;i++)
	cin>>a[i];
	
	int ans=0;
	int count=0;
	if(a[n]==n)
	{
		cout<<n-1;
		return 0;
	}
	if(a[n]==1000&&a[n]-a[1]==n-1)
	{
		cout<<n-1;
		return 0;
	}
	for(i=2;i<n;i++)
	{
		if((a[i]==a[i-1]+1)&&(a[i]+1==a[i+1]))
		count++;
		else
		{
			ans=max(ans,count);
			count=0;
		}
	}
	ans=max(ans,count);
	cout<<ans<<"\n";
//	cout<<"count"<<count;
}
