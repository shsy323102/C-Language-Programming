#include<stdio.h>
#include<stdlib.h> 
int main()
{
	char a[1000];
	int x;
	int i;
	scanf("%d",&x);
	getchar();
	while(x>0)
	{
		gets(a);
		for(i=0;a[i]!='\0';i++)
		{
			
		}
		i=i-1;
		for(;i>=0;i--)
		{
			printf("%c",a[i]);
		}
		printf("\n");
		x--;
	}
 } 
