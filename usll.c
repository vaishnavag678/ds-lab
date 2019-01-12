#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE N;


N *insert(N *head,int x)
{
	N *temp,*p;
	temp=(N *)malloc(sizeof(N));
	
	temp->data=x;
	temp->next=NULL;
	
	if(head==NULL)
	return temp;
	p=head;
	
	while(p->next!=NULL)
	p=p->next;
	
	p->next=temp;
	
	return head;
}
void print(N *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	
	
}
N *delete(N *head)
{
	N *temp,*p,*q;
	
	temp=head;
	
	int val;
	
	while(temp!=NULL)
	{
		p=temp->next;
		val=temp->data;
		
		while(p!=NULL)
		{
			if(p->data==val)
			{
				N *alpha;
				alpha=p;
				temp->next=p->next;
				p=p->next;
				free(alpha);
			}
			else
			p=p->next;
			
		}
		temp=temp->next;
	}
	
	return head;
}


int main()
{
	int x,i,n;
	N *head=NULL;
	printf("enter the number of element \n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("enter the element you want to enter ");
		scanf("%d",&x);
		head=insert(head,x);
	}
	
	printf("your current list is \n");
	print(head);
	
	delete(head);
	
	printf("\n");
	printf("your updated list is \n");
	print(head);
}
