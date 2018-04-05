#include<stdio.h>
int main()
{
	int a[20][20];
	int x,y,sum;
	

	int i,j;
	

	scanf("%d%d",&x,&y);
				for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			
			a[i][j]=0;
		}
		
	}
			for(i=0;i<y;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&sum);
			a[j][i]=sum*3;
		}
		
	}

		for(i=0;i<x;i++)
		{
				for(j=0;j<y;j++)
		{
	
			
			printf("%-8d",a[i][j]);
		
		}
		printf("\n");
	}

}


