#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define null NULL
struct Linkedlist
{
	int data;
	struct Linkedlist *next;	
};
typedef struct Linkedlist node;
node *addnode(node * head,int value)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data=value;
	temp->next=head;
	return temp;
}
void display(node *head)
{
	if(head==null) return;
	
	display(head->next);
	printf("%d",head->data);
}
node *addNumbers(node *head1,node *head2)
{
	node *p=head1,*q=head2;
	int sum=0;
	while(p!=null&&q!=null)
	{
		int temp = p->data+q->data+sum;
		p->data=(temp)%10;
		sum=temp/10;
		p=p->next;
		q=q->next;
	}
	if(sum!=0&&p!=null)
	{
		p->data+=sum;
		return head1;
	}
	else if(sum!=0) 
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data=sum;
		temp->next=null;
		node *p=head1;
		while(p->next!=null) p=p->next;
		p->next=temp;
	}
	return head1;
}
int main()
{
	printf("Enter numbers to be added\n");
	char num1[100];
	char num2[100];
	scanf("%s",num1);
	scanf("%s",num2);
	int len1=strlen(num1);
	int n=len1,i;
	node *head1=null;
	for( i=0;i<n;i++)
	{
		head1=addnode(head1,num1[i]-'0');
	} 
	int len2=strlen(num2);
	n=len2;
	node *head2=null;
	for( i=0;i<n;i++)
	{
		head2=addnode(head2,num2[i]-'0');
	}	
	node *head=null;
	if(len2<=len1) head = addNumbers(head1,head2);
	else head = addNumbers(head2,head1);
	display(head);
	return 0;
}
