#include<stdio.h>
int main()
{
	int x;
	long int a;
	int cnt=0;
	int i;
	scanf("%d",&x);
	while(x>0)
	{
		scanf("%ld",&a);
		for(i=1;i<=a;i++)
		{
			if(a%i==0)
			cnt++;
		}
		printf("%d\n",cnt);
		cnt=0;
		x--;
	}
	
	 return 0;
}
