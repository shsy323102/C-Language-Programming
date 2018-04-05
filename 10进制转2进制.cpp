#include<stdio.h>
int main()
{
        int i,j,x,a[1000];
        while(scanf("%d",&x)!=EOF)
        {
	
        for(i=0;;i++)
        {
                a[i]=x%2;
                x=x/2;
                if(x==0)
                        break;
        }
        for(j=i;j>=0;j--)
                printf("%d",a[j]);
                printf("\n");
            }
        return 0;
}
