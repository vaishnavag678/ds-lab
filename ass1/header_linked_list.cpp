#include<stdio.h>
#include<stdlib.h>
#define null NULL
struct linkNode
{
	int data;
	struct linkNode *next;
};
typedef struct linkNode node;
node *addnode(node *head,int data)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next=null;
	if(head==null)
	{
		return temp;
	}
	node *p=head;
	while(p->next!=null)
	{
		p=p->next;
	}
	p->next=temp;
	return head;
}
node *insertAtStart(node *head,int data)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next=null;
	if(head==null) return temp;
	temp->next=head;
	return temp;
}
node *insertBefore(node *head,int x,int data)
{
	node *temp = (node*)malloc(sizeof(node)),*p=head;
	temp->data = data;
	temp->next=null;
	if(head==null) 
	{
		printf("Empty List!!\n");
		return head;
	}
	if(head->next==null&&head->data==x)
	{
		temp->next=head;
		return temp;
	}
	while(p->next!=null&&(p->next->data)!=x)	p=p->next;
	if(p->next==null)
	{	
		printf("Element Not Found\n");
		return head;
	}
	temp->next=p->next;
	p->next=temp;
	return head;
}
node *insertAfter(node *head,int x,int data)
{	
	node *temp = (node*)malloc(sizeof(node)),*p=head;
	temp->data = data;
	temp->next=null;
	if(head==null) 
	{
		printf("Empty List!!\n");
		return head;
	}
	while(p!=null&&(p->data)!=x)	p=p->next;
	if(p==null)
	{	
		printf("Element Not Found\n");
		return head;
	}
	temp->next=p->next;
	p->next=temp;
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
	if(p->next==null)
	{	
		free(p);
		return null;
	}
	while(p->next->next!=null)
	{
		p=p->next;
	}
	free(p->next);
	p->next=null;
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
	while(p!=null&&p->data!=x) p=p->next;
	if(p==null)
	{
		printf("Element Not Found\n");
		return head;
	}
	if(p->next==null)
	{
		printf("No element after given element \n");
		return head;
	}
	node *q=p->next;
	p->next=q->next;
	free(q);
	return head;
}
void display(node *head)
{
	if(head==null)
	{
		printf("Empty List\n");
		return;
	}
	while(head!=null)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
int main()
{
	node* head=(node*)malloc(sizeof(int));
	head->data=null;
	head->next=null;
	do
	{
		//printf("Enter 1 for adding new node at end followed by dataEnter 2 for inserting node at start of list\nEnter 3 to insertbefore some element followed by data of that element and new node data\nEnter 4 inserting after some element followed by element data and new node data\nEnter 5 to delete first node\nEnter 6 to delete last node\nEnter 7 to delete node after a element followed by element data\nEnter 8 to display the list\nEnter 0 to exit\n");
		  		printf("enter 1 for ins at front 2 for insat end 3 for inaaf 4 for inbf 5 for display 6 for delete 0 for exit\n");
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

