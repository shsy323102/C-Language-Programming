#include<stdio.h>
int main()
{
	int i,j,k;
	int m;
	int h;
	scanf("%d%d%d",&i,&j,&k);
	if(i>j&&j<=k)
	printf("Impossible!");
	else if (i<=j)
	{
		printf("1");
	} else {
		h=j-k;
		m=2;
		while(h+j<i)
		{
			m++;
			h=h+j-k;
		}
			printf("%d",m);
	}

	return 0;
}
