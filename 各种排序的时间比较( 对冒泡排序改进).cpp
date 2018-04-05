//�ļ���:excise6.cpp
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <time.h>
#define MaxSize 50001
typedef int KeyType;
void initial(int R[],int low,int high)	//����R[low..high�е������
{
	int i;
	srand((unsigned)time(NULL));
	for (i=low;i<high;i++)
	{
		if(i<30000)
		R[i]=rand()%99+1;
		else
		R[i]=i;
	} 
}
bool test(KeyType R[],int low,int high)	//��֤����������ȷ��
{
	int i;
	for (i=low;i<high-1;i++)
		if (R[i]>R[i+1])
			return false;
	return true;
}
void Difference(struct _timeb timebuf1,struct _timeb timebuf2)	//��ʱ���
{
	long s,ms;
	s=timebuf2.time-timebuf1.time;			//��ʱ����������
	ms=timebuf2.millitm-timebuf1.millitm;	//��ʱ�����ĺ�����
	if (ms<0)
	{
		s--;
		ms=1000+ms;
	}
	printf("%d��%d����",s,ms);
}
//-------ֱ�Ӳ�������----------
void InsertSort(KeyType R[],int n)
{
	int i,j;
	KeyType tmp;
	for (i=1;i<n;i++)
	{
		tmp=R[i];
		j=i-1;				//����������������R[0..i-1]����R[i]�Ĳ���λ��
		while (j>=0 && tmp<R[j])
		{	R[j+1]=R[j];	//���ؼ��ִ���R[i]��Ԫ�غ���
			j--;
		}
		R[j+1]=tmp;			//��j+1������R[i]
	}
}
void InsertSortTime()		//��ֱ�Ӳ��������ʱ��
{
	KeyType R[MaxSize];
	int n=50000;
	struct _timeb timebuf1,timebuf2;
	printf("ֱ�Ӳ�������\t");
	initial(R,0,n-1);
	_ftime(&timebuf1);
	InsertSort(R,n);
	_ftime(&timebuf2);
	Difference(timebuf1,timebuf2);
	if (test(R,0,n-1))
		printf("\t��ȷ\n");
	else
		printf("\t����\n");
}
//------�۰��������----------
void InsertSort1(KeyType R[],int n)
{
	int i,j,low,high,mid;
	int tmp;
	for (i=1;i<n;i++)
	{
		tmp=R[i];					//��R[i]���浽tmp��
		low=0;high=i-1;
		while (low<=high)			//��R[low..high]���۰������������λ��
		{
			mid=(low+high)/2;		//ȡ�м�λ��
			if (tmp<R[mid])
				high=mid-1;			//������������
			else
				low=mid+1;			//��������Ұ���
		}
		for (j=i-1;j>=high+1;j--)	//Ԫ�غ���
			R[j+1]=R[j];
		R[high+1]=tmp;				//����
	}
}
void InsertSort1Time()		//���۰���������ʱ��
{
	KeyType R[MaxSize];
	int n=50000;
	struct _timeb timebuf1,timebuf2;
	printf("�۰��������\t");
	initial(R,0,n-1);
	_ftime(&timebuf1);
	InsertSort1(R,n);
	_ftime(&timebuf2);
	Difference(timebuf1,timebuf2);
	if (test(R,0,n-1))
		printf("\t��ȷ\n");
	else
		printf("\t����\n");
}
//-----------ϣ�������㷨--------------
void ShellSort(KeyType R[],int n)
{
	int i,j,gap;
	KeyType tmp;
	gap=n/2;				//�����ó�ֵ
	while (gap>0)
	{	for (i=gap;i<n;i++) //���������gapλ�õ�����Ԫ�������ֱ�Ӳ�������
		{	
			tmp=R[i];
			j=i-gap;
			while (j>=0 && tmp<R[j])//�����gapλ�õ�Ԫ�����������
			{	R[j+gap]=R[j];
				j=j-gap;
			}
			R[j+gap]=tmp;
		}
		gap=gap/2;	//��С����
	}
}
void ShellSortTime()		//��ϣ�������㷨��ʱ��
{
	KeyType R[MaxSize];
	int n=50000;
	struct _timeb timebuf1,timebuf2;
	printf("ϣ������\t");
	initial(R,0,n-1);
	_ftime(&timebuf1);
	ShellSort(R,n);
	_ftime(&timebuf2);
	Difference(timebuf1,timebuf2);
	if (test(R,0,n-1))
		printf("\t��ȷ\n");
	else
		printf("\t����\n");
}
//--------ð�������㷨----------
void BubbleSort(KeyType R[],int n)
{
	int i,j;
	bool exchange;
	KeyType tmp;
		for (i=0;i<n-1;i++) 
	{
		exchange=false;
		for (j=0;j<n-i-1;j++)	//�Ƚ�,�ҳ����ؼ��ֵ�Ԫ��
			if (R[j]>R[j+1])
			{	tmp=R[j];	//R[j]��R[j+1]���н���,�����ؼ���Ԫ��ǰ��
				R[j]=R[j+1];
				R[j+1]=tmp;
				exchange=true;
			}
		if (!exchange)		//����û�з�����������;�����㷨
			return;
	}
}
void BubbleSort2(KeyType R[],int n)
{
	int i;
	int c=0; 
	int exchange=n-1;
	KeyType tmp; 
	while(exchange){
		for(c=0,i=0;i<exchange;i++){
			if(R[i]>R[i+1]){
				tmp=R[i];
				R[i]=R[i+1];
				R[i+1]=tmp;
				c=i;
			}
		}
		exchange=c;
	
	}
}
void BubbleSortTime()		//��ð�������㷨��ʱ��
{
	KeyType R[MaxSize];
	int n=50000;
	struct _timeb timebuf1,timebuf2;
	printf("ð������\t");
	initial(R,0,n-1);
	_ftime(&timebuf1);
	BubbleSort(R,n);
	_ftime(&timebuf2);
	Difference(timebuf1,timebuf2);
	if (test(R,0,n-1))
		printf("\t��ȷ\n");
	else
		printf("\t����\n");
}
void BubbleSortTime2()		//��ð�������㷨��ʱ��
{
	KeyType R[MaxSize];
	int n=50000;
	struct _timeb timebuf1,timebuf2;
	printf("ð������(�Ż�)\t");
	initial(R,0,n-1);
	_ftime(&timebuf1);
	BubbleSort2(R,n);
	_ftime(&timebuf2);
	Difference(timebuf1,timebuf2);
	if (test(R,0,n-1))
		printf("\t��ȷ\n");
	else
		printf("\t����\n");
}
//--------���������㷨---------------
void QuickSort(KeyType R[],int s,int t)
{
	int i=s,j=t;
	KeyType tmp;
	if (s<t) 				//���������ٴ�������Ԫ�ص����
	{
		tmp=R[s];			//������ĵ�1��Ԫ����Ϊ��׼
		while (i!=j)		//���������˽������м�ɨ��,ֱ��i=jΪֹ
		{
			while (j>i && R[j]>=tmp) 
				j--;		//��������ɨ��,�ҵ�1��С��tmp��R[j]
			R[i]=R[j];		//�ҵ�������R[j],R[i]��R[j]����
			while (i<j && R[i]<=tmp) 
				i++;		//��������ɨ��,�ҵ�1������tmp��Ԫ��R[i]
			R[j]=R[i];		//�ҵ�������R[i],R[i]��R[j]����
		}
		R[i]=tmp;
		QuickSort(R,s,i-1);	//��������ݹ�����
		QuickSort(R,i+1,t);	//��������ݹ�����
	}
}
void QuickSortTime()		//����������㷨��ʱ��
{
	KeyType R[MaxSize];
	int n=50000;
	struct _timeb timebuf1,timebuf2;
	printf("��������\t");
	initial(R,0,n-1);
	_ftime(&timebuf1);
	QuickSort(R,0,n-1);
	_ftime(&timebuf2);
	Difference(timebuf1,timebuf2);
	if (test(R,0,n-1))
		printf("\t��ȷ\n");
	else
		printf("\t����\n");
}
//---------ֱ��ѡ������
void SelectSort(KeyType R[],int n)
{	int i,j,k;
	KeyType tmp;
	for (i=0;i<n-1;i++)			//����i������
	{	k=i;
		for (j=i+1;j<n;j++)		//�ڵ�ǰ������R[i..n-1]��ѡkey��С��R[k]
			if (R[j]<R[k])
				k=j;			//k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��
		if (k!=i)				//����R[i]��R[k]
		{	tmp=R[i];
			R[i]=R[k];
			R[k]=tmp;
		}
	}
}
void SelectSortTime()		//��ֱ��ѡ�������㷨��ʱ��
{
	KeyType R[MaxSize];
	int n=50000;
	struct _timeb timebuf1,timebuf2;
	printf("ֱ��ѡ������\t");
	initial(R,0,n-1);
	_ftime(&timebuf1);
	SelectSort(R,n);
	_ftime(&timebuf2);
	Difference(timebuf1,timebuf2);
	if (test(R,0,n-1))
		printf("\t��ȷ\n");
	else
		printf("\t����\n");
}
//----------�������㷨-------
void sift(KeyType R[],int low,int high)
{	
	int i=low,j=2*i;						//R[j]��R[i]������
	KeyType tmp=R[i];
	while (j<=high)
	{
		if (j<high && R[j]<R[j+1]) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;
		if (tmp<R[j]) 
		{	R[i]=R[j];						//��R[j]������˫�׽ڵ�λ����
			i=j;							//�޸�i��jֵ,�Ա��������ɸѡ
			j=2*i;
		}
		else break;							//ɸѡ����
	}
	R[i]=tmp;								//��ɸѡ�ڵ��ֵ��������λ��
}
void HeapSort(KeyType R[],int n)
{
	int i;
	KeyType tmp;
	for (i=n/2;i>=1;i--)	//ѭ��������ʼ��
		sift(R,i,n); 
	for (i=n;i>=2;i--)		//����n-1�����������,ÿһ�˶������Ԫ�ظ�����1
	{
		tmp=R[1];			//�����һ��Ԫ��ͬ��ǰ������R[1]�Ի�
		R[1]=R[i];
		R[i]=tmp;
		sift(R,1,i-1);		//ɸѡR[1]�ڵ�,�õ�i-1���ڵ�Ķ�
	}
}
void HeapSortTime()			//��������㷨��ʱ��
{
	KeyType R[MaxSize];
	int n=50000;
	struct _timeb timebuf1,timebuf2;
	printf("�� �� ��\t");
	initial(R,1,n);
	_ftime(&timebuf1);
	HeapSort(R,n);
	_ftime(&timebuf2);
	Difference(timebuf1,timebuf2);
	if (test(R,1,n))
		printf("\t��ȷ\n");
	else
		printf("\t����\n");
}
//--------��·�鲢�����㷨------------
void Merge(KeyType R[],int low,int mid,int high) 
{
	KeyType *R1;
	int i=low,j=mid+1,k=0; //k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
	R1=(KeyType *)malloc((high-low+1)*sizeof(KeyType));  //��̬����ռ�
	while (i<=mid && j<=high)		//�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
		if (R[i]<=R[j])		//����1���е�Ԫ�ط���R1��
		{	R1[k]=R[i];
			i++;k++;
		}
		else						//����2���е�Ԫ�ط���R1��
		{	R1[k]=R[j];
			j++;k++; 
		}
	while (i<=mid)					//����1�����²��ָ��Ƶ�R1
	{	R1[k]=R[i];
		i++;k++;
	}
	while (j<=high)					//����2�����²��ָ��Ƶ�R1
	{	R1[k]=R[j];
		j++;k++;
	}
	for (k=0,i=low;i<=high;k++,i++) //��R1���ƻ�R��
		R[i]=R1[k];
	free(R1);
}
void MergePass(KeyType R[],int length,int n)	//�������������һ�˹鲢
{	int i;
	for (i=0;i+2*length-1<n;i=i+2*length)	//�鲢length�����������ӱ�
		Merge(R,i,i+length-1,i+2*length-1);
	if (i+length-1<n)					//���������ӱ�,���߳���С��length
		Merge(R,i,i+length-1,n-1);		//�鲢�������ӱ�
}
void MergeSort(KeyType R[],int n)	//�Ե����ϵĶ�·�鲢�㷨
{	int length;
	for (length=1;length<n;length=2*length)//����log2n�˹鲢
		MergePass(R,length,n);
}
void MergeSortTime()			//���·�鲢�����㷨��ʱ��
{
	KeyType R[MaxSize];
	int n=50000;
	struct _timeb timebuf1,timebuf2;
	printf("��·�鲢����\t");
	initial(R,0,n-1);
	_ftime(&timebuf1);
	MergeSort(R,n);
	_ftime(&timebuf2);
	Difference(timebuf1,timebuf2);
	if (test(R,0,n-1))
		printf("\t��ȷ\n");
	else
		printf("\t����\n");
}
int main()
{
	printf("�������50000��1-99��������,�������򷽷��ıȽ�\n");
	printf("------------------------------------------------\n");
	printf("���򷽷�         ��ʱ         �����֤\n");
	printf("------------------------------------------------\n");
	InsertSortTime();
	InsertSort1Time();
	ShellSortTime();
	BubbleSortTime();
	BubbleSortTime2();
	QuickSortTime();
	SelectSortTime();
	HeapSortTime();
	MergeSortTime();
	printf("------------------------------------------------\n");
return 0;
}
