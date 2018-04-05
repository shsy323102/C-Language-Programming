#include<stdio.h>
int main()
{
	int t;
	int m;
	scanf("%d",&t);
	int x,y;
	int i,j;
	int a[40];
	while(t>0)
	{
	
		scanf("%d",&x);
		scanf("%d",&y);
		for(i=0;i<x;i++)
		{
			scanf("%d",&m);
			a[i]=m;
		}
		for(j=i;j<x+y;j++)
		{
			scanf("%d",&m);
			a[j]=m;
		}
		for(i=0;i<x+y;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
			t--;
	}
}
