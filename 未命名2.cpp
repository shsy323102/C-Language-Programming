#include<stdio.h>
int main()
{
 	int i;
 	int n;
 	int cnt=0;
 	int m;
 	int arr[40];
 	scanf("%d",&m);
for(n=2;n<=m;n++)
{
	int t=n; 
	int s=t;
	int sum=1;
 	for(i=2;i<t;i++)
 	{
 		if(t%i==0)
 		{
		 sum=sum+i;
		}
		
	 }
	 if(sum==s)
	 {
		 printf("%d its factors are 1,",sum);
	 		for(i=2;i<s;i++)
 				{
 					
 					if(s%i==0)
 					{	
 						arr[cnt]=i;
 						cnt++;
					 }
				}	
				for(i=0;i<cnt;i++)
				{
					if(i<cnt-1)
					{
						printf("%d,",arr[i]);
					}
					else
					{
						printf("%d",arr[i]);
					}
				}
				printf("\n");
				cnt=0;
	}
}
	 return 0;
}
