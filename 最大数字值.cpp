#include<stdio.h>
int main()
{
	long int x;
	scanf("%ld",&x);
	if(x<0)
	x=-x;
	int t;
	int cnt=0;
	t=x%10;
	if(x==0)
	printf("0 1");
	else{
	
    while(x>0)
    {
    	if(t<x%10)
    	{
    		t=x%10;
		}
    	if(x%10==0)
    	{
    		cnt++;
		}
		x=x/10;
	}
	printf("%d %d",t,cnt);
}
}
