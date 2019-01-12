#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,q,k,x,y,z,i,j;
	int var;
	cin>>n>>q>>k;
	
	int s[600005];
	
	for(i=n;i>0;i--)
	{
		cin>>s[i];
	}
	string query;
	
	cin>>query;
	int start=0;
	int end=0;
	int maxlen=0;
	int maxi=0;
	int slen=0;
	int ans=0;
	for(i=n;i>0;i--)
	{
		if(s[i]==0)
		break;
		
		start++;
	}
	for(i=1;i<=n;i++)
	{
		if(s[i]==0)
		break;
		end++;
	}
	ans=max(start,end);
	// yaha tumne maxlen calcualte kiya age dekh lena thoda 
	int count=0;
	for(i=n;i>0;)
	{
		count=0;
		if(s[i]==1)
		{
		
			while(s[i]!=0&&i>0)
			{
				count++;
				i--;
			}
			if(count>ans)
			{
				ans=max(count,ans);
				maxlen=i+1;
			}
		}
		else
		i--;
	}
	ans=max(ans,count);
	maxi=ans;
	count=0;
	ans=0;
	
	for(i=1;i<=n;i++)
	{
		count=0;
		if(s[i]==1)
		{
			while(s[i]!=0)
			{
				count++;
				i++;
			}
			if(count>ans&&count<maxi)
			ans=count;
		}
		else
		i++;
	}

	slen=max(ans,count);
	cout<<"start "<<start<<"\n";
	cout<<"end "<<end<<"\n";
	cout<<"firstlen "<<maxi<<"\n";
	cout<<"slen "<<slen<<"\n";
	
	int starting=n;
	int ending=1;
	for(j=0;j<q;j++)
	{
		if(query[j]=='!')
		{
			if(s[ending]==1)
			{
				s[++starting]=s[ending++];
				
				if(maxlen==ending)
				{
					maxi--;
					start++;
					
					if(start>maxi)
					{
						maxi=start;
						maxlen=starting-start+1;
					}
				}
				else
				{
					if(maxlen==starting-start+1)
					maxi++;
					
					start++;
				}
			}
			else
			{
					s[++starting]=s[ending++];
					start=0;
			}
		}
		else if(query[i]='?')
		{
			if(start>maxi)
			{
				maxi=start;
				maxlen=starting-start+1;
			}
			ans=max(maxi,max(slen,start));
			
			if(ans>k)
			cout<<k<<"\n";
			else
			cout<<ans<<"\n";
		}
	
	}
	return 0;
}
