#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,s,i;
	cin>>n>>s;
	if(n==1)
	{
		if(s>9){
		cout<<-1<<" "<<-1;
		return 0;
		}
		cout<<s<<" "<<s;
		return 0;
	}
	string s1,s2;
	int sum=s;
	if(s<1||s>9*n)
	{
		cout<<-1<<" "<<-1;
		return 0;
	}
	for(i=0;i<n-1;i++)
	{
		int digit=min(s-1,9);
		s=s-digit;
		s1+=(char)(digit+'0');
	}
	s1+=(char)(s+'0');
	reverse(s1.begin(),s1.end());
	cout<<s1<<" ";
	s=sum;
	for(i=0;i<n;i++)
	{
		int digit=min(s,9);
		s=s-digit;
		s2+=(char)(digit+'0');
	}
	cout<<s2;
}
