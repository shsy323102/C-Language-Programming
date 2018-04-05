#include<stdio.h>
int main()
{
	double x;
	int i;
	for(x=0;x!=400;x=x+20)
	{
	printf("%-8.2f",(double)5/9*(x-32));
	if((i+1)%4==0)
	printf("\n");
	i++;
}

 } 
