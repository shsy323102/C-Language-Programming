#include<stdio.h>
int main()
{
	 long int a[16][16];
	int x;
	int i,j; 
	int k;
	scanf("%d",&x);
	a[1][1]=1;
	for(i=0;i<x;i++)
	{
		for(j=0;j<x;j++)
		{
			a[i][0]=1;
			if(i==j)
			{
				a[i][j]=1;
			}
			a[i][j+1]=a[i-1][j]+a[i-1][j+1];
		}
	}
	for(i=0;i<x;i++)
	{
		for(k=0;k<x-i;k++)
		{
			printf("  ");
		}
		for(j=0;j<x;j++)
		{
			if(j<=i)
			printf("%2d  ",a[i][j]);
		}
		printf("\n");
	}
}
