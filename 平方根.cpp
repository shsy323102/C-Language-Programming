#include<stdio.h>
#include<math.h>
int main()
{
	int x;
	float y;
	float a,b;
	scanf("%d",&x);
	while(x>0)
	{
		scanf("%f",&y);
		if(y==0)
		printf("0.000");
		else
	{
		 
		a=y/2;
		b=(a+y/a)/2;
		do
		{
			a=b;
			b=(a+y/a)/2;
		}while(fabs(b-a)>1e-6); 
		printf("%.3f %.3f\n",-b,b);
	}
		x--;
	}
}
