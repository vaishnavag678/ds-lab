#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
                    /*******************stack **********************/

struct Node
{
 	 int info;
  	struct Node *next;
} ;
typedef struct Node N;
					/**********************************vaishnavagrawal*****************************/

N* push(N* head,int x)
{
	N *p;
	p=(N*)malloc(sizeof(N));
	p->info=x;
	p->next=head;
  
   return p;
}
N* pop(N* head)
{
   	if(head==NULL)
   	{
   		printf("stack is empty");
   		return NULL;
   	}
   	if(head->next==NULL)
   	{
   	   return NULL;
    }
    N *p=head;
    head=head->next;
    free(p);
    return head;
}
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
int main()
{
	N* head;
	head=NULL;
	
	int t,entry;
	t=1;
	while(t!=0)
	{
	    printf("\n1forpush  2forpop 3fordisplay 0forexit ");
		scanf("%d",&t);
		if(t==1)
		{
		  printf("enter the element you want to enter ");
		  scanf("%d",&entry);
		  head=push(head,entry);
		}
		if(t==2)
		{
		   head=pop(head);
		}
		if(t==3)
		{
		   display(head);
		}
     } 
		  
}











