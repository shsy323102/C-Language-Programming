#include<stdio.h>
int main()
{
	int n,m;
	int sum;
	scanf("%d%d",&n,&m);
	int a[10][10];
	int i,j; 
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	sum=a[0][0];
		for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(sum<a[i][j])
			sum=a[i][j];
		}
	}
	printf("%d",sum);
}
