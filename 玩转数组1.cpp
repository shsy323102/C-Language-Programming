#include<stdio.h>
int main()
{
	int a[20][20];
	int b[20][20];
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
			for(i=0;i<x;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&sum);
			a[i][j]=sum*3;
		}
		
	}

		for(i=0;i<x;i++)
		{
				for(j=0;j<y;j++)
		{
	
			if(i==x)
			printf("%d",a[i][j]);
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}


