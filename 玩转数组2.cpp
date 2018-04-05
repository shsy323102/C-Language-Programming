#include<stdio.h>
int main()
{
	int a[20][20];
	int b[20][20];
	int x,y,sum;
	int cnt;
	sum=1;
	int i,j;
	scanf("%d",&cnt);
	while(cnt>0)
	{
	
	scanf("%d%d",&x,&y);
			for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			a[i][j]=sum++;
		}
		
	}

		for(j=0;j<y;j++)
	{
		for(i=0;i<x;i++)
		{
			if(i==x)
			printf("%d",a[i][j]);
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	cnt--;
	sum=1;
}

}
