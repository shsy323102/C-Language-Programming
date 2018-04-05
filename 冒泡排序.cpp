#include<stdio.h>
int main()
{
	int a[1000];
	int n,i,j;
	int sum=0;
	int t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				
			}
		}
	}

		for(i=n-1;i>0;i--)
		{
			printf("%d ",a[i]);
			sum+=a[i];
		}
    printf("%d\n%d",a[0],sum+a[0]);

		return 0;
}
