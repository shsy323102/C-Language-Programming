#include<stdio.h>
#define WIDE 10
#define HIGHT 17
int main()
{
	int i;
	int j;
	int a,b;
	int change;
	int count;
	int arr[HIGHT][WIDE]={
		0,0,0,0,0,1,1,0,0,0,
		0,0,0,0,0,0,1,0,0,0,
		0,0,0,0,1,0,1,0,0,0,
		0,0,0,0,0,1,1,0,0,0,
		0,0,0,0,1,0,1,0,0,0,
		0,0,0,0,0,1,0,1,0,0,
		0,0,0,0,0,0,1,0,0,0,
		0,10,0,0,0,0,0,1,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,1,0,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,0
	}; 
	for(i=0;i<HIGHT;i++)
	{
		for(j=0;j<WIDE;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	int x;
	int y;
	int k;
	for(i=HIGHT-1;i>=0;i--)
	{
		for(j=WIDE-1;j>=0;j--)
		{
			change=0;
			count=0;
			while(arr[i-change][j-change]==1)
			{
				change++;
				count++;
				if(i-change<0||j-change<0)
				{
					break;
				}
			}
			if(count>3)
			{
				printf("i=%d j=%d\n",i,j);
				printf("i=%d j=%d\n",i-change+1,j-change+1);
				k=0;
				for(k=0;k<count;k++)
				{
					arr[i-k][j-k]=0;
				}
//					for(b=j;b>j-change;b--)
//					{
//						
//						for(a=i-k;a>0;a--)
//						{
//							arr[a][b]=arr[a-1][b];
//						}
//						k++;
//					}
						for(i=0;i<HIGHT;i++)
						{
							for(j=0;j<WIDE;j++)
							{
								printf("%d ",arr[i][j]);
							}
							printf("\n");
						}	
			}
				count=0;
				change=0;
			while(arr[i-change][j+change]==1)
			{
				change++;
				count++;
				if(i-change<0||j+change>WIDE-1)
				{
					break;
				}
			
			}
			if(count>3)
			{
					printf("(%d,%d)\n",i,j);
					printf("(%d,%d)\n",i-change+1,j+change-1);
//					k=0;
//					for(b=j;b<j+change;b++)
//					{
//						
//						for(a=i-k;a>0;a--)
//						{
//							arr[a][b]=arr[a-1][b];
//						}
//						k++;
//					}
				for(k=0;k<count;k++)
				{
					arr[i-k][j+k]=0;
				}
			}
		}
	}
//		for(i=0;i<HIGHT;i++)
//	{
//		for(j=0;j<WIDE;j++)
//		{
//			printf("%d ",arr[i][j]);
//		}
//		printf("\n");
//	}
}
