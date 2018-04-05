#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a+b>c&&a+c>b&&b+c>a)
	{
		if(a==b&&a==c&&b==c)
		{
			printf("DB");
		}
		else 
			if(a==b||a==c||b==c)
			{
			printf("DY");
			} else if(a*a==b*b+c*c||b==a*a+c*c||c*c==a*a+b*b)
			printf("ZJ");
			else
				{
					printf("YB");
				}
	}
	else
	{
		printf("ERROR");
	}
}
