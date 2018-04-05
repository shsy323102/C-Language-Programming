#include<stdio.h>
int main()
{
	int x;
	long int a[100];
	a[0]=1;
	a[1]=1;
	int i;
	for(i=2;i<40;i++)
	{
		a[i]=a[i-2]+a[i-1];
	}
  scanf("%d",&x); 
  
  	printf("%ld",a[x-1]);
  
 } 
