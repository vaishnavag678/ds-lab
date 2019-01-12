#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
					/**********************************vaishnavagrawal*****************************/
                         /****************polynomial addition******************/

struct Node
{
 	 int info;
 	 int power;
  	struct Node *next;
} ;
typedef struct Node N;
                        /**********************************vaishnavagrawal*****************************/
N* push(N* head,int x,int pow)
{
   	N *p,*q=head;
   	p=(N*)malloc(sizeof(N));
    p->info=x;
    p->power=pow;
    p->next=NULL;
    
    if(head==NULL)
     return p;
    
    while(q->next!=NULL)
    q=q->next;
     
     q->next=p;
     
  
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
     printf("%dx^%d ",head->info,head->power);
     head=head->next;
   }
}
N* add(N *head1,N *head2,N *head3)
{
   N *p=head1,*q=head2;
   
   while(p!=NULL&&q!=NULL)
   {
   
     		if(p->power>q->power)
     		{
     			head3=push(head3,p->info,p->power);
     		//	printf("%d ",p->power);
     			p=p->next;
     		}
     		else if(q->power>p->power)
     		{
     			head3=push(head3,q->info,q->power);
     		//	printf("%d ",q->power);
     			q=q->next;
     		}
     		else
     		{
        		 		if(p->info+q->info==0)
         				{ 
           					 p=p->next;
            				q=q->next;
          				}
          				else
          				{
           					 head3=push(head3,p->info,p->power);
             				p=p->next;
            				q=q->next;
           				}
       		}
	}	
       if(p==NULL)
       {
          while(q!=NULL)
           {
           		  	head3=push(head3,q->info,q->power);
     				q=q->next;
			}
		}
		else
		{
			 while(p!=NULL)
           {
           		  	head3=push(head3,p->info,p->power);
     				p=p->next;
			}
		}
    

  return head3;
}		
int main()
{
	 N *head1,*head2,*head3;
	head1=NULL;
	head2=NULL;
	head3=NULL;
    
    printf("give polynomial 1 ");
    int t=3;
    int coff,pow;
    while(t>0)
    {
    	printf("\nenter the coff and pow : ");
    	 scanf("%d%d",&coff,&pow);
    	head1=push(head1,coff,pow);
    	t--;
    }
    printf("give polynomial 2\n ");
    
    t=3;
    while(t>0)
    {
    	printf("\nenter the coff and pow : ");
    	 scanf("%d%d",&coff,&pow);
    	head2=push(head2,coff,pow);
    	t--;
    }
    
    t=1;
    while(t>0)
    {
       printf("\n1 for poly1 2forpoly 2 3formergedpoly \n");
       scanf("%d",&t);
       
       if(t==1)
        display(head1);
        if(t==2)
        display(head2);
        if(t==3)
        {
           head3=add(head1,head2,head3);
           display(head3);
           t=0;
        }
      }
       
}

























