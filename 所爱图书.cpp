#include<stdio.h>
int main()
{
	int a[100];
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
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				
			}
		}
	}

		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
			 if(a[j]==a[i])
			 {
			 	a[j]=-1;
			 }
			}

		}
		for(i=0;i<n;i++)
		{
			if(a[i]!=-1)
			printf("%d ",a[i]);
		}

		return 0;
}
