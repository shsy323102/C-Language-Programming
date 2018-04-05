#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int i;
	float a[1000];
	int max=0;
	for(i=0;i<x;i++)
	{
		scanf("%f",&a[i]);
	}
	for(i=1;i<x;i++)
	{
		if(a[0]<a[i])
		{
		a[0]=a[i]; 
		max++;
        }
	}
	printf("%.3f %d",a[0],max);
	return 0; 
} 
