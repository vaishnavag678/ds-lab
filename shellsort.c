#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int i,j,temp,gap;
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	  for ( gap = n/2; gap > 0; gap /= 2) 
   		 {
          
       		 for ( i = gap; i < n; i += 1) 
       		 { 
           		  temp = a[i];
           		             
            	for (j = i; j >= gap && a[j - gap] > temp; j -= gap) 
                a[j] = a[j - gap]; 
           		 a[j] = temp; 
       		 } 
   		 } 
   	for(i=0;i<n;i++)
   	printf("%d ",a[i]);
}
