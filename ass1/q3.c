#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
 N* check(N* head)
 {
 	N *p=head,*q;
 	if(head==NULL)
 	{
 	  printf("LIST IS EMPTY ");
 	  return head;
 	}
   
         while(p->next!=NULL)
         {
         		if(p->data==p->next->data)
   		{
   			q=p->next;
   			p->next=q->next;
   			free(q);
   		}
   		else
   		p=p->next;
   	}
   
   return head;
   }
   int main()
   {
    
     N *head;
     head=(N*)malloc(sizeof(N));
     int t=1,x;
     
     head=NULL;
     
    	 while(t!=0)
    	 {
    	   printf("1 to add 2 to display list\n3to delete duplicate entry 0 to exit : ");
       		scanf("%d",&t);
       
       		 if(t==1)
 		{
 	 	 printf("enter the element to add : ");
 	 	 scanf("%d",&x);
 	 	 head=add(head,x);
 	  	printf("\n");
 		 }
        		if(t==2)
        		{
        		  display(head);
        		  printf("\n");
        		}
        		if(t==3)
        		{
        		  head=check(head);
         		 display(head);
         		 printf("\n");
         		}
    	 }
  }
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	 
 	  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
 
 
