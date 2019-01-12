#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next; //vessi
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
N* merge(N* h1,N* h2)
  {
  	N *p=h1,*q=h2,*h3=NULL;
  	
  	if(h1==NULL)
  	return h2;
  	if(h2==NULL)
  	return h1;
  	
  	while(h1!=NULL&&h2!=NULL)
  	{
  	  if(h1->data>h2->data)
		{
		 h3=add(h3,h2->data);
		  h2=h2->next;	
		}	
	   else if(h1->data<h2->data)
		{
		 h3=add(h3,h1->data);
		  h1=h1->next;	
		}	
		else if(h1->data==h2->data)
		{
		  h3=add(h3,h1->data);
		  h1=h1->next;
		  h2=h2->next;	
		}	
		
	}
	if(h1!=NULL)
	{
		while(h1!=NULL)
		{
		h3=add(h3,h1->data);
			h1=h1->next;
		}
	}
     else
	{
		while(h2!=NULL)
		{
		 h3=add(h3,h2->data);
		 h2=h2->next;
		}
	}
	
	return h3;
  }
int main()
{
	int n,x;
	N *h1,*h2,*h3;
	h1=NULL;
	h2=NULL;
	h3=NULL;
		printf("ENTER THE ELEMENT YOU WANT TO ENTER IN LIST 1 : ");
		scanf("%d",&n);
		printf("\n");
		int i;
		for(i=1;i<=n;i++)
		{
		   printf("enter the element you want to push: ");
		   scanf("%d",&x);
		  h1=add(h1,x);
		   printf(" ");
		}
			printf("ENTER THE ELEMENT YOU WANT TO ENTER IN LIST 2 : ");
		scanf("%d",&n);
		printf("\n");
	//	int i;
		for(i=1;i<=n;i++)
		{
		   printf("enter the element you want to push: ");
		   scanf("%d",&x);
		   h2=add(h2,x);
		   printf(" ");
		}
		printf("YOUR LIST 1 IS  ");
		display(h1);
		printf("\n");
		printf("YOUR LIST 2 is  ");
		display(h2);
		printf("\n");
	    h3=merge(h1,h2);
		printf("The merged list is : ");
	    display(h3);
}

  
