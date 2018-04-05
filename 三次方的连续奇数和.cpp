#include<stdio.h>
int main()
{
	int n,i,k,j,sum;
	scanf("%d",&n);
	k=n*n*n;
	int sta=0;
	for(i=1;i<k/2;i=i+2) 
	{
		for(j=i,sum=0;j<k/2;j+=2)
		{
			sum+=j;
			if(sum==k)
			{
				printf("%d %d %d\n",k,i,j);
				
			}
		}
	}
		return 0;
}

