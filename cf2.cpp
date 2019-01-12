#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int main()
{
	ll n;
	cin>>n;
	
	ll i;
	
	ll prev=0;
	ll count=0;
	ll y;
	while(n!=prev)
	{
		ll x=(ll)sqrt(n);
		if(x*x==n){
		n=x;
		}
		else
		{
			for(i=2;i<n;i++)
			{
				y=(ll)sqrt(n*i);
				if(y*y==n*i)
				{
					n=n*i;
					break;
				}
				
			}
		}
		count++;
	}
	cout<<n<<" "<<count-1;
}
