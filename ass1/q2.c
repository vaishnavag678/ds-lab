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
  N* merge(N* h1,N *h2)
  {
  	N* P;
          //if(h1==NULL&&h2==NULL)
          //return NULL;
          
  	if(h1==NULL)
  	return h2;
  	
  	if(h2==NULL)
  	return h1;
  	N* p=h1;
  	
      while(p->next!=NULL)
       p=p->next;
       
       p->next=h2;
       
   return h1;
   }
  		
 int main()
 {
   N *h1,*h2;
   
  	 h1=(N*)malloc(sizeof(N));
     
     	 h2=(N*)malloc(sizeof(N));
   
   	h1=NULL;
   	h2=NULL;
   	
   	
   	int t=1;
   	int x;
   	
   	while(t!=0)
   	{
   	   printf("1 to insert in 1st list  2nd to insert in 2nd list  3 merge 2 in 1  4 merge 1 in 2 0 to exit\n ");
   	   scanf("%d",&t);
   	   
   	  	 if(t==1)
   	   	{
   	    	 printf("enter the element you want to enter : ");
   	    	scanf("%d",&x);
   	     	h1=add(h1,x);
   	    	}
   	   
   	   	if(t==2)
   	   	{
   	    	 printf("enter the element you want to enter : ");
   	    	 scanf("%d",&x);
   	     	h2=add(h2,x);
   	    	}
   	   	 if(t==3)
   	   	{
   	     
   	    	 //scanf("%d",&x);
   	    	 h1=merge(h1,h2);
   	     	h2=NULL;
   	     	display(h1);
   	     	printf("\n");
   	   	}
   	   	if(t==4)
   	  	 {
   	     
   	 	 //scanf("%d",&x);
   	    	 h2=merge(h2,h1);
   	  	 h1=NULL;
   	     	display(h2);
   	     	printf("\n");
   	 	  }
   	 }
   	 
   	   
         }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
   
