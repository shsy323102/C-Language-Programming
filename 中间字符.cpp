#include<stdio.h>
int main()
{
	char a[100];
	gets(a);
	int i;
	int j;
	int cnt=0;
   for(i=0;a[0]!='\n';i++)
   {
   	if(a[i]=='A')
   	{
   		while(a[++i]!='A')
   		{
   			cnt++;
		   }
		   j=i;
		   break;
	   }
	  
   }
   printf("%d\n",cnt);
    for(i=i-cnt;i<j;i++)
	   {
	   	printf("%c",a[i]);
	   }
}
