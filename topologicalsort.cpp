#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct S
{
	int succ;
	struct S* next;
};
typedef struct S s;
struct C
{
	int count;
	s* down;
};
typedef struct C c;
c* arr[1000];
void insert(int a,int b)
{
	(arr[b]->count)++;
	s* x = (s*)malloc(sizeof(s));
	x->succ=b;
	x->next=NULL;
	if(arr[a]->down==NULL)
	{
		arr[a]->down=x;		
	}
	else
	{
		s* p = arr[a]->down;
		while(p->next!=NULL)
			p=p->next;
		p->next=x;
	}
}
void dec(int i)
{
	if(arr[i]->down==NULL)
	{
		return;
	}
	else
	{
		s* p=arr[i]->down;
		while(p!=NULL)
		{
			arr[p->succ]->count--;
			p=p->next;
		}
		
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	int hash[t+1];
	for(i=0; i<=t; i++)
	{
		hash[i]=1;
		arr[i]=(c*)malloc(sizeof(c));
		arr[i]->count=0;
		arr[i]->down=NULL;
	}
	printf("Enter the number of edges\n");
	int q;
	scanf("%d",&q);
	for(i=0; i<q; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		insert(a,b);
	}
	int j;
	for(j=0; j<t; j++)
	{
		for(i=1; i<=t; i++)
		{
			if(hash[i]==1 && arr[i]->count==0)
			{
				hash[i]=0;
				dec(i);
				printf("%d ",i);
				break;
			}
		}
	}
	return 0;
}
