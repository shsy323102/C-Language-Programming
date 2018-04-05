#include<stdio.h>
#include<math.h>
int main()
{
	int x;
	int y;
	int i;
	scanf("%d%d",&x,&y);
 	float sum=1;
	for(i=1;i<=y;i++)
	{
		sum=sum*x; 
	}
	printf("%.1f\n",sum);
} 
