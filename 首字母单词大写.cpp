#include<stdio.h>
int main()
{
	char a[1000];
	gets(a);
	int i;
	for(i=1;a[i]!='\0';i++)
	{
		if('a'<=a[0]&&a[0]<='z')
		{
			a[0]=a[0]-32;
		}
		if(a[i-1]==' '&&'a'<=a[i]&&a[i]<='z')
		{
			a[i]=a[i]-32;
		}
	}
	puts(a);
}
