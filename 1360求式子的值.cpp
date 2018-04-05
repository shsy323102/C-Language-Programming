#include<stdio.h>
int main() 
{
	int x;
	int i;
	int j;
	scanf("%d",&x);
	long sum;
	long long sum2=0;
	for(j=1;j<=x;j++)
	{
		sum=1;
		for(i=1;i<=j;i++)
		{
			sum*=i;
		}
		sum2+=sum;
	}
	printf("%lld",sum2);
}
