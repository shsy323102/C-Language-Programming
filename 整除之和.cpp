#include<stdio.h>
int main()
{
   int n;
   int i;
   int sum=0;
   int cnt=0;
   scanf("%d",&n);
   for(i=n;i>10;i--)
   {
   	if(i%11==0||i%19==0)
   	{
   		if(cnt<10)
   		{
   			sum+=i;
   			cnt++;
		   }
		   else break;
	   }
   	
	 }
	 printf("%d",sum);
 } 
