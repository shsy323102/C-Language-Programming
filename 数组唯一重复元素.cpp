#include<stdio.h>
int main()
{
	int x;
	int i,j;
	int sta=0;
	int a[100];
	while(scanf("%d",&x)!=EOF)
	{
		for(i=0;i<x;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<x-1;i++)
		{
			for(j=i+1;j<x;j++)
			{
				if(a[i]==a[j])
				{
				
				printf("%d",a[i]);
				sta=1;
				}
			}
		}
		if(sta==0)
		{
			printf("Null");
		}
		sta=0;
		printf("\n");
		
	}
}
