#include<stdio.h>
#include<stdlib.h>


struct DNODE
{
	int data;
	struct DNODE *next,*prev;
};
typedef struct DNODE D;

D* insert(D *head,int x)
{
	D *temp=NULL,*n,*p;
	n=(D*)malloc(sizeof(D));
	n->data=x;
	n->next=NULL;
	n->prev=NULL;
	
	if(head==NULL)
	{
	    n->next=n;
	    n->prev=n;
	    return n;
	}
	temp=head;p=temp;
	
	
	while(temp->next!=head&&temp->data<x)
	{   p=temp;
		temp=temp->next;
	}
	if(temp->next==head)
	{
		n->next=head;
		n->prev=temp;
		temp->next=n;
		head->prev=n;
	}
	else if(temp->data>=x)
	{
		n->next=temp;
		n->prev=p;
		p->next=n;
		temp->prev=n;
	}
	return head;
}
D *del(D *head)
{
	D *temp=NULL,*n,*p,*q;
	
	if(head==NULL)
	return NULL;
	D *x;
	x=head->prev;
	if(head->prev==head)
	{
		free(head);
		return NULL;
	}else{
		x->next=head->next;
		p=head;
		head=head->next;
		free(p);
	}
	
	if(head->prev==head)
	{
		free(head);
		return NULL;
	}else{
		q=head->prev;
		p=q;
		q=q->prev;
		q->next=head;
		head->prev=q;
		free(q);
	}
	return head;
}

void print(D *head)
{
    D *temp=head;
    while(head->next!=temp){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("%d ",head->data);
}
int main()
{
	D *head=NULL;
	int t,entry;
	printf("1 for insert 2 for delete 3 for print \n");
	
	do{
		printf("enter choice \n");
		scanf("%d",&t);
		
		if(t==1)
		{
			printf("enter your entry");
			scanf("%d",&entry);
			head=insert(head,entry);
		}
		else if(t==2)
		head=del(head);
		else if(t==3)
		print(head);
		printf("\n");
		
	}while(t!=0);
}
