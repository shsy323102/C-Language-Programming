#include<stdio.h>
int main()
{
	int n;
	int sum=0;
	scanf("%d",&n);
	int a[10][10];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
		for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j||i+j==n-1)
			sum+=a[i][j];
		}
	}
	printf("%d",sum);
}
