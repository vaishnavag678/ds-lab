#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *left,*right;
};
typedef struct NODE N;

struct QUEUE{
	N *a[100];
	int front;
	int rear;
};
typedef struct QUEUE Q;

void push(Q *q,N *x)
{
	q->a[++q->rear]=x;
}
N *pop(Q *q)
{
	return q->a[q->rear--];
}

int solve(N *head)
{
	Q *queue=(Q*)malloc(sizeof(Q));
	queue->front=0;
	queue->rear=-1;
	
	push(queue,head);
	int count=0;
	while(queue->rear!=-1)
	{
		N *temp=pop(queue);
		
		if(temp->left!=NULL)
		push(queue,temp->left);
		if(temp->right!=NULL)
		push(queue,temp->right);
		if(temp->right==NULL&&temp->left==NULL)
		count++;
	}
	return count;
}

N *newnode(int data)
{
	N *temp;
	temp=(N*)malloc(sizeof(N));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}



int main()
{
	N *head=NULL;
	head=newnode(1);
	head->left=newnode(2);
	head->right=newnode(3);
	head->left->left=newnode(4);
	head->left->right=newnode(5);
	
	printf("%d",solve(head));
}
