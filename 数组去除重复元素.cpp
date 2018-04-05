#include<stdio.h>
int main()
{
 	int m,n;
	scanf("%d%d",&m,&n);
	 int i,j,k;
	 int a[20];
	 int l=m+n;
	 for(i=0;i<l;i++)
	 {
		scanf("%d",&a[i]);
	 }	
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(a[i]==a[j])
			{
				for(k=j+1;k<l;k++)
				{
					a[k-1]=a[k];
				}
					l--;
			}
		}
	}
	for(i=0;i<l;i++)
	{
		printf("%d ",a[i]);
	}
} 
