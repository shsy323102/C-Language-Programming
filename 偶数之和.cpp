#include<stdio.h>
#include<math.h>
int main()
{
	int cnt;
	int m,i,k;
	scanf("%d",&cnt);
	while(cnt>0)
	{
	 scanf("%d",&m);
   k=(int)sqrt(m);
   for(i=2;i<=k;i++)
      if(m%i==0)
         break;
   if(i>k)
       printf("Yes\n");
   else
       printf("No\n");
       cnt--;
   }
   return 0;
}
