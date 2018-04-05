#include<stdio.h>
#include<math.h>
int main()
{
	int x;
	int n;
	int cnt;
	int i;
	scanf("%d",&x);
	while(x>0)
	{
		cnt=0;
		scanf("%d",&n);
		for(i=1;i<=sqrt(n);i++)
		{
				if(n%i==0)
				{
					if(i*i==n)
					{
						cnt+=i;
				}
				else
				{
					cnt+=i;
					cnt+=n/i;
				}
		}
	}
		printf("%d\n",cnt);
		x--;
	}
}
