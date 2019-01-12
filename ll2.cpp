#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
		ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll n;
	ll i;
	
	while(t--)
	{
		cin>>n;
		ll a[n+1];
		ll hash[n+1]={0};
		
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			//hash[a[i]]++;
		}
		for(i=1;i<=n;i++)
		hash[i]=a[a[i]];
		
		ll flag=0;
		
		vector<pair<ll,ll> >v;
		for(i=1;i<=n;i++)
			v.push_back(make_pair(hash[i],a[i]));
			
			sort(v.begin(),v.end());
			
			for(i=0;i<n-1;i++)
			{
				if(v[i].first==v[i+1].first&&v[i].second!=v[i+1].second)
				{
					flag=1;
					break;
				}
			}
	
		if(flag==1)
		cout<<"Truly Happy"<<"\n";
		else
		cout<<"Poor Chef"<<"\n";
		
	}
	return 0;
}
