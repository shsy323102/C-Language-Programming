#include<stdio.h>
int main()
{
	int x,y;
	char a[100][21];
	scanf("%d",&x);
	getchar();
	int i,j;
	int t;
	int max=0;
	for(i=0;i<x;i++)
	{
		gets(a[i]);
		for(j=0;a[i][j]!='\0';j++)
		{
			
		}
		if(max<=j)
		{
			max=j;
			t=i;
		}
	
	}
	for(j=0;j<max;j++)
	{
		printf("%c",a[t][j]);
	}
	
}
