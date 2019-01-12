#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main()
{
	ll t;
	cin>>t;
	ll n,count;
	ll bit,nibble,byte;
	while(t--)
	{
		cin>>n;
		n=n-1;
	//	count=1;
		bit=1;
		nibble=0;
		byte=0;
		while(n>0)
		{
			if(n-2>=0)
			{
				n=n-2;
				nibble=bit;
				bit=0;
				byte=0;
			}
			else
			break;
			if(n-8>=0)
			{
				n=n-8;
				byte=nibble;
				nibble=0;
				bit=0;
			}
			else
			break;
			if(n-16>=0)
			{
				n=n-16;
				bit=2*byte;
				nibble=0;
				byte=0;
			}
			else
			break;
		}
		cout<<bit<<" "<<nibble<<" "<<byte<<"\n";
	}
}
