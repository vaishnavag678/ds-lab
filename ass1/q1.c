#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
 int data;
 struct node* next;
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
  int len(N* head,int count)
  {
  	if(head->next==NULL)
  	 return count;
  	 
  	// head=head->next;
  	 
  	 return len(head->next,count+1);
    }
    
    int main()
    {
    	N *head;
    	head=(N*)malloc(sizeof(N));
    	
    	head=NULL;
    	
    	int t=1,x,count=0;
    	
    	while(t!=0)
    	{
    	  printf(" 1 for add \n 2 for len 0 for exit\n");
    	  scanf("%d",&t);
    	  
    	  if(t==1)
    	  {
    	  	printf("\nenter the element you want to add\n");
    	    	scanf("%d",&x);
    	    	head=add(head,x);
    	  }
    	  if(t==2)
    	  {
    	  	x=len(head,count);
    	  	printf("\n your length is %d\n",x+1);
    	  }
    	  
    	 }
    return 0;
   }
    	    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
