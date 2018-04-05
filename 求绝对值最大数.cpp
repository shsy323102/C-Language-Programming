#include<stdio.h>
#include<math.h>
int main()
{
	int x;
	int a[1000];
	int b[1000];
	int i;
	int j;
	int sta=0;
	int min;
	int m;
	scanf("%d",&x);
	while(x>0)
	{
		scanf("%d",&j);
		for(i=0;i<j;i++)
		{
			scanf("%d",&a[i]);
		}
		min=a[0];
		for(i=1;i<j;i++)
		{
			if(abs(min)>abs(a[i]))
			{
				min=a[i];
			}
		}
		if(min<0)
		{
			for(i=0;i<j;i++)
			{
				if(-min==a[i])
				{
					min=a[i];
				}
			}
		}
		printf("%d\n",min);
		x--;
	}
}

