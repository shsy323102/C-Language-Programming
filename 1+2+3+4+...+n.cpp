#include<stdio.h>
int main()
{
	int x;
	int i;
	long int m;
	scanf("%d",&x);
	while(x>0)
	{
		scanf("%ld",&m);
		if(m%2==0)
		{
			printf("%ld",m/2*(m+1));
		}
		else
		{
			printf("%ld",(m+1)/2*m);
		}
		x--;
	}
 } 
