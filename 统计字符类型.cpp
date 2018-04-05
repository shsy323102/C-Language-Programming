#include<stdio.h>
int main()
{
	char a[100];
	gets(a);	
	int i;
	int x,b,c,d;
	x=0;
	b=0;
	c=0;
	d=0;
	for(i=0;a[i]!='\0';i++)
	{
		if('a'<=a[i]&&a[i]<='z'||'A'<=a[i]&&a[i]<='Z')
		x++;
		else if('0'<=a[i]&&a[i]<='9')
		b++;
		else if(a[i]==32)
		c++;
		else d++;
	}
	printf("%d %d %d %d",x,b,c,d);
	return 0;
}
