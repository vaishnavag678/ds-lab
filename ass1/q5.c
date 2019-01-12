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
   	 printf("YOUR LIST IS  ");
    
    	while(head!=NULL)
    	{
    	  printf("%d ",head->data);
    	  head=head->next;
    	 }
  }
  N* reverse(N* head)
  {
    // three pointers approach 
    N *p,*q,*r;
    q=head;
    p=NULL;
    	while(q->next!=NULL)
    	{
    		r=q->next;
    		q->next=p;
    		p=q;
    		q=r;
    	}
    	q->next=p;
    	
    return q; 
  }
  void compar(N *h1,N *h2)
  {
    	while(h1!=NULL)
    	{
		if(h1->data!=h2->data)
		{
			printf("NOT A PALINDROME \n");
			return;
		}
		h1=h1->next;
		h2=h2->next;
	}
	printf("YES ITS A PALINDROME");
  }       
  
    
  int main()
  {
   N *head,*head2;
   head=NULL;
   head2=NULL;
   int t=1,x;
   
   	while(t!=0)
   	{
   		printf("1 for insert 2 for diplay 3 for compare :  ");
   		scanf("%d",&t);
   		
   		
   		if(t==1)
   		{
   			printf("\n ENTER THE ELEMENT YOU WANT TO INSERT : ");
   			scanf("%d",&x);
   			head=add(head,x);
   			head2=add(head2,x);
   			printf("\n");
   		}
   		if(t==2)
   		{
   		  	display(head);
   		  	printf("\n");
   		 }
   		 if(t==3)
   		 {
   		 	head=reverse(head);
   		 	display(head);
   		 	compar(head,head2);
   		  	printf("\n");
   		  	t=0;
   		  }
   	}
   	
   	return 0;
   }
   		  	  
  
   

