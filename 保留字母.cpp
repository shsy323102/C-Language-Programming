#include<stdio.h>
int main()
{
	char a[100];
	int i;
	while(scanf("%s",a)!=EOF)
	{
		for(i=0;a[i]!='\0';i++)
		{
			if('a'<=a[i]&&a[i]<='z'||'A'<=a[i]&&a[i]<='Z')
			{
				printf("%c",a[i]);
			}
		}
		printf("\n");
	}
 } 
