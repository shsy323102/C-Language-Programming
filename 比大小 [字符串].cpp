#include<stdio.h>
int main()
{
	int x;
	int i,j;
	int sta;
	char a[100000],b[100000];
	for(i=0;i<1000;i++)
		{
			a[i]=0;
			b[i]=0;
		}
	scanf("%d",&x);
	while(x>0)
	{
		sta=0; 
		scanf("%s",a);
		scanf("%s",b);
		i=0;
		while(a[i]!='\0')
		{
			i++;
		}
		j=0;
		while(b[j]!='\0')
		{
			j++;
		}
  		if(i>j)
  		{
  			puts(a);
		}
		else if(i<j)
		{
			puts(b);
		} 
		else 
		{
				i--;
			while(i>=0)
			{
				if(a[i]>b[i])
				{
					puts(a);
					sta=1;
					break;
				}
				i--;
			}
			if(sta==0)
			puts(b);
		}
		
		x--;
	}
	return 0;
}
