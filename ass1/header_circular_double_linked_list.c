#include<stdio.h>
#include<stdlib.h>
#define null NULL
struct HCDlinkNode
{
	int data;
	struct HCDlinkNode *prev,*next;
};
typedef struct HCDlinkNode node;
node *addnode(node *head,int data)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->prev=temp;
	temp->next=temp;
	if(head==null)
	{
		return temp;
	}
	node *p=head;
	while(p->next!=head)
	{
		p=p->next;
	}
	p->next=temp;
	temp->prev=p;
	temp->next=head;
	head->prev=temp;
	return head;
}
node *insertAtStart(node *head,int data)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->prev=temp;
	temp->next=temp;
	if(head==null) return temp;
	temp->next=head;
	temp->prev=head->prev;
	temp->prev->next=temp;
	head->prev=temp;
	return temp;
}
node *insertBefore(node *head,int x,int data)
{
	node *temp = (node*)malloc(sizeof(node)),*p=head;
	temp->data = data;
	temp->prev=temp;
	temp->next=temp;
	if(head==null) 
	{
		printf("Empty List!!\n");
		return head;
	}
	if(head->next==head&&head->data==x)
	{
		temp->next=head;
		temp->prev=head->prev;
		head->prev=temp;
		temp->prev->next=temp;
		return temp;
	}
	while(p->next!=head&&(p->next->data)!=x)	p=p->next;
	if(p->next==head)
	{	
		printf("Element Not Found\n");
		return head;
	}
	temp->prev=p;
	temp->next=p->next;
	p->next=temp;
	temp->next->prev=temp;
	return head;
}
node *insertAfter(node *head,int x,int data)
{	
	node *temp = (node*)malloc(sizeof(node)),*p=head;
	temp->data = data;
	temp->prev=null;
	temp->next=null;
	if(head==null) 
	{
		printf("Empty List!!\n");
		return head;
	}
	while(p->next!=head&&(p->data)!=x)	p=p->next;
	if(p->next==head&&p->data!=x)
	{	
		printf("Element Not Found\n");
		return head;
	}
	temp->prev=p;
	temp->next=p->next;
	p->next=temp;
	temp->next->prev=temp;
	return head;
}
node *deleteFirst(node *head)
{
	if(head==null)
	{
		printf("Empty List!!\n");
		return head;
	}
	node *p=head->next;	
	p->prev=head->prev;
	p->prev->next=p;
	free(head);
	return p;
}
node *deleteEnd(node *head)
{
	if(head==null)
	{
		printf("Empty List!!\n");
		return head;
	}
	node *p=head;
	if(p->next==head)
	{	
		free(p);
		return null;
	}
	while(p->next->next!=head)
	{
		p=p->next;
	}
	head->prev=p;
	free(p->next);
	p->next=head;
	return head;
}
node *deleteAfter(node *head,int x)
{
	if(head==null)
	{
		printf("Empty List!!\n");
		return head;
	}
	node *p=head;
	while(p->next!=head&&p->data!=x) p=p->next;
	if(p->next==head&&p->data!=x)
	{
		printf("Element Not Found\n");
		return head;
	}
	node *q=p->next;
	p->next=q->next;
	q->next->prev=p;
	free(q);
	return head;
}
void display(node *head)
{
	node *p=head;
	if(head==null)
	{
		printf("Empty List\n");
		return;
	}
	while(p->next!=head)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}
int main()
{
	node* head=(node*) malloc(sizeof(node));
	head->data=-1;
	head->prev=null;
	head->next=null;
	do
	{
		printf("Enter 1 for adding new node at end followed by data\nEnter 2 for inserting node at start of list\nEnter 3 to insertbefore some element followed by data of that element and new node data\nEnter 4 inserting after some element followed by element data and new node data\nEnter 5 to delete first node\nEnter 6 to delete last node\nEnter 7 to delete node after a element followed by element data\nEnter 8 to display the list\nEnter 0 to exit\n");
		int ty;
		scanf("%d",&ty);
		if(ty==1) 
		{
			int data;
			scanf("%d",&data);
			head->next=addnode(head->next,data);
		}
		if(ty==2) 
		{
			int data;
			scanf("%d",&data);
			head->next=insertAtStart(head->next,data);
		}
		if(ty==3) 
		{
			int data,x;
			scanf("%d%d",&x,&data);
			head->next=insertBefore(head->next,x,data);
		}
		if(ty==4) 
		{
			int data,x;
			scanf("%d%d",&x,&data);
			head->next=insertAfter(head->next,x,data);
		}
		if(ty==5) 
		{
			head->next=deleteFirst(head->next);
		}
		if(ty==6) 
		{
			head->next=deleteEnd(head->next);
		}
		if(ty==7) 
		{
			int x;
			scanf("%d",&x);
			head->next=deleteAfter(head->next,x);
		}
		if(ty==8) display(head->next);
		if(ty==0) break;
	}while(1);
	return 0;
}

