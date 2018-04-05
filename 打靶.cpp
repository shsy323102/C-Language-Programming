#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int i,j,k;
	for(i=1;i<=y/10;i++)
	{
		for(j=1;j<=y/7;j++)
		{
			for(k=1;k<y/5;k++)
			{
				if(i*10+j*7+k*5==y)
				{
					printf("%d %d %d\n",i,j,k);
			
				}
			}
		}
	}
	return 0;
 } 
