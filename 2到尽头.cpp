#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int cnt =0;
    while(x!=1)
    {
    	if(x%2==0)
    	{
    		x/=2;
		}
		else
		{
			x=(x+1)/2;
		}
		cnt++;
	}
	printf("%d",cnt);
}
