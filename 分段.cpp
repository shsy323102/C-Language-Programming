#include<stdio.h>
int main()
{
	int x;
	double i;
	scanf("%d",&x);
	while(x>0)
	{
		scanf("%lf",&i);
		if(i<0)printf("0.000");
		else if(i>=0&&i<10)printf("%.3f",i);
		else if(i>=10&&i<20)printf("10.000");
		else printf("%.3f",-0.5*i+20);
		printf("\n");
		x--;
	 } 
}
