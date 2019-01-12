#include<stdio.h>
#include<stdlib.h>


struct DNODE
{
	int data;
	struct DNODE *next,*prev;
};
typedef struct DNODE D;


D *insert(D *head,int x)
{
	D *n,*temp;
	n=(D*)malloc(sizeof(D));
	n->next=NULL;
	n->prev=NULL;
	n->data=x;
	
	if(head==NULL)
	{
		n->next=n->prev=n;
		return n;
	}
	D *last=head->prev;
	last->next=n;
	n->prev=last;
	n->next=head;
	head->prev=n;
	
    return head;	
}
void print(D *head)
{
    D *temp=head;
    while(head->next!=temp){
        printf("%d ",head->data);
        head=head->next;
    }
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
	   
		else if(t==3)
		print(head);
		printf("\n");
		
	}while(t!=0);
}
