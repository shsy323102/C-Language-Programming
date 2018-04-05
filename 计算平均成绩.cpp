#include<stdio.h>
int main()
{
	int a[5][3];
	int i,j;
	int sum=0;
	int avg=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",a[i][j]);
			avg+=a[i][j];
		}
		printf("%.2lf",(double)avg/3);
		avg=0;
		printf("\n");
	}
	printf("%.2lf",(double)sum/15);
	return 0;
} 
