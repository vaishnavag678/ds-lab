#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
                   /**********************************vaishnavagrawal*****************************/
                        /***************** merging last part to front part*******************/ 
struct Node
{
 	 int info;
  	struct Node *next;
} ;
typedef struct Node N;
void display(N *head)
{
   if(head==NULL)
   {
     printf("list is empty ");
     return;
   }
   while(head!=NULL)
   {
     printf("%d ",head->info);
     head=head->next;
   }
}

N* push(N* head,int x)
{
   	N* p,*q=head;
   	p=(N*)malloc(sizeof(N));
    p->info=x;
    p->next=NULL;
    
    if(head==NULL)
     return p;
    
    while(q->next!=NULL)
    q=q->next;
     
     q->next=p;
     
  
   return head;
}
N* merge(N *head)
{
	N *p=head,*q,*head2;
	int len=0;
	
	if(head==NULL)
	return NULL;
	
	
	while(p->next!=NULL)
	{
	  len++;
	  p=p->next;
	}
	len++;
	printf("length= %d\n",len);
	int x=len/2;
	p=head;
	
	while(x>1)
	{
		p=p->next;
		x--;
	}
	head2=p->next;
	p->next=NULL;
	q=head2;
	if(head2==NULL)
	return head;
	
	while(q->next!=NULL)
	 q=q->next;
	 
	 q->next=head;
  return head2;
  
}
int main()
{
	N* head;
	head=NULL;
	
	int t,entry;
	t=1;
	while(t!=0)
	{
	    printf("\n1forpush 2 formerge 3fordisplay 0forexit ");
		scanf("%d",&t);
		if(t==1)
		{
		  printf("enter the element you want to enter ");
		  scanf("%d",&entry);
		  head=push(head,entry);
		}
		if(t==2)
		{
			head=merge(head);
		}
		if(t==3)
		{
		   display(head);
		}
     }
		  
}

















