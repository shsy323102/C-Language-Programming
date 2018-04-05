#include<stdio.h>
int main()
{
	int m,n;
	int a[10][10];
	scanf("%d%d",&m,&n);
	int i;
	int j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int max=a[0][0];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(max<a[i][j])
			max=a[i][j];
		}
	}
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(max==a[i][j])
			printf("%d %d %d",max,i,j);
		}
	}
	return 0;
}
