#include<stdio.h>
int main()
{
	double a[1000];
	double c[1000];
	int x;
	int i;
	double max;
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		scanf("%lf",&a[i]);
	}
	double b=a[0];
	for(i=0;i<x;i++)
	{
		c[i]=a[i];
	}
	for(i=0;i<x;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	for(i=0;i<x;i++)
	{
		if(c[i]==max)
		{
			printf("%.3f %d",max,i);
		}
	}
	return 0;
}

