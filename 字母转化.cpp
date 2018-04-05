#include<stdio.h>
int main()
{
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		getchar();
		if('A'<=c&&c<='Z')
		printf("%c",c+32);
		else if(c>='a'&&c<='z')
		printf("%c",c-32);
		else printf("%c",c);
		printf("\n");
	}
 } 
