#include<stdio.h>
int main()
{
	int x;
	char a[1000000];
	int i;
	int max;
	int b[26];
	scanf("%d",&x);
	getchar();
	while(x>0)
	{
		for(i=0;i<26;i++)
		{
			b[i]=0;
		}
		gets(a);
		for(i=0;a[i]!='\0';i++)
		{
			if('a'<=a[i]&&a[i]<='z')
			{
				b[a[i]-'a']++;
			}
		}
		max=0;
		for(i=0;i<26;i++)
		{
			if(b[max]<b[i])
			max=i;
		}
		printf("%c\n",max+'a');
		x--;
	}
}

