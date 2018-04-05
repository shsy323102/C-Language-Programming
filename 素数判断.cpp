#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,x,i;
	scanf("%d\n",&a);
	while(a--)
	{
		scanf("%d",&b);
		x=(int)sqrt(b);
		for(i=2;i<=x;i++)
		{
			if(b%i == 0)
			break;
		}
		if(i>x && b!=1 && b!=0)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}
