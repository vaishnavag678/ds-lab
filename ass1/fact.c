#include<stdio.h>

int fact(int n)
{
	if(n==0||n==1)
	return 1;
	
	return n*fac(n-1);
	
}

int main()
{
	int x;
	printf("enter the number for factorial calculation\n");
	scanf("%d",&x);
	
	printf("factorial of x is %d",fact(x));
	
	return 0;
}
