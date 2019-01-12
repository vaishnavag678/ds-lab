#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
 };
 typedef struct node N;
 N* add(N* head,int x)
 {
    	N *p=head,*newnode;
    	newnode=(N*)malloc(sizeof(N));
    
   	 newnode->data=x;
    	newnode->next=NULL;
    
   		 if(head==NULL)
    		{
    			//newnode->next=NULL;
    			 return newnode;
    		}
    	while(p->next!=NULL)
  	 p=p->next;
    
    	p->next=newnode;
   	 
   	 return head;
    
  }
   void display(N* head)
  {
    	if(head==NULL)
   	 {
    		printf("LIST IS EMPTY");
     		return ;
   	 }
   	// printf("YOUR LIST IS  ");
    
    	while(head!=NULL)
    	{
    	  printf("%d ",head->data);
    	  head=head->next;
    	 }
  }
N* delalternate(N* head)
{
	N *p=head;
	
	if(head==NULL||head->next==NULL)
	  return head;
	N *q;
	q=head->next;  
	 
	 while(q!=NULL)
	 {
	 	p->next=q->next;
	 	free(q);
	 	
	 	p=p->next;
	 	
	 	if(p!=NULL)
	 	q=p->next;
	 	else
	 	break;
	 } 
  return head;	
}
int main()
{
	N *head;
	head=NULL;
	int n,i,x;
	printf("enter the number of element of list: ");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("enter the element you want to add: ");
		scanf("%d",&x);
		head=add(head,x);
		printf("\n");
	}
	printf("your initial list is : ");
	display(head);
	printf("\n");
	head=delalternate(head);
		printf("your final list is : ");
		display(head);
	
}
