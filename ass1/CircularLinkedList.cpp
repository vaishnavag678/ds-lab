
#include<bits/stdc++.h>
#define null NULL
using namespace std;
struct Node
{
	int data;
	struct Node *next;	
};
typedef struct Node node;
void display(node *head)
{
	node *p=head;
	if(p==null)
	{
		printf("Empty List!!\n");
		return;
	}
	while(p->next!=head)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}
node *addnode(node *head,int value)
{
	node *p=(node *)malloc(sizeof(node));
	p->data=value;
	if(head==null)
	{
		p->next=p;
		return p;
	}
	p->next=head;
	node *q=head;
	while(q->next!=head)
	{
		q=q->next;
	}
	q->next=p;
	return head;
}
node *insertAfter(node *head,int location,int value)
{
	node *q=(node *)malloc(sizeof(node));
	q->data=value;
	node *p=head;
	if(head==null)
	{
		printf("Empty List!!\n");
		return head;
	}
	if(head->data==location)
	{
		q->next = p->next;
		p->next = q;
		return head;
	}
	p=p->next;
	while(p!=head&&p->data!=location)
	{
		p=p->next;
	}
	if(p==head)
	{
		printf("Not Found!\n");
		return head;
	}
	q->next=p->next;
	p->next=q;
	return head;
}
node *deleteEnd(node *head)
{
	node *p=head;
	if(head==null)
	{
		printf("Empty list!!\n");
		return head;
	}
	if(head->next==head)
	{
		free(head);
		return null;
	}
	while((p->next)->next!=head)
	{
		p=p->next;
	}
	free(p->next);
	p->next=head;
	return head;
}
node *deleteAfter(node *head,int location)
{
	node *p=head;
	if(head==null)
	{
		printf("List is Empty!!\n");
		return head;
	}
	if(head->data==location)
	{
		if(head->next!=head)
		{
			node *q=head->next;
			p->next=q->next;
			free(q);
			return head;
		}
		else
		{
			printf("No element after %d\n",location);
			return head;
		}
	}
	p=p->next;
	while(p!=head&&p->data!=location)
	{
		p=p->next;	
	}
	if(p==head||(p->data==location&&p->next==head))
	{
		printf("Not Found\n");
		return head;
	}
	node *q=p->next;
	p->next=q->next;
	free(q);
	return head;
}
int main()
{
	node *head = null;
	printf("Enter Number of numbers to input\n");
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		head=addnode(head,a);
	}
	do
	{
		printf("Enter 1 to remove last node\nEnter 2 to add a node followed by the data\nEnter 3 to add a node after node follwed by node data and data\nEnter 4 to delete node after node data followed by data\nEnter 5 to display\nEnter 0 to exit\n");
		int ty;
		scanf("%d",&ty);
		if(ty==0) break;
		if(ty==1)
		{
			head=deleteEnd(head);
		}
		else if(ty==2)
		{
			int value;
			scanf("%d",&value);
			head=addnode(head,value);
		}
		else if(ty==3)
		{
			int loc,value;
			scanf("%d%d",&loc,&value);
			head=insertAfter(head,loc,value);
		}
		else if(ty==4)
		{
			int loc;
			scanf("%d",&loc);
			head=deleteAfter(head,loc);
		}
		else if(ty==5)
		{
			display(head);
		}
			
	}while(1);
	return 0;
}
