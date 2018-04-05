#include<iostream>
using namespace std;

typedef struct LNode										//���嵥����
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void InitList_L(LinkList &L)								//����������
{
	L=new LNode;
	L->next=NULL;
}

void input(LinkList &L,int n)								//������������L����������
{
	int i;
	LinkList p,r;
	r=L;
	cout<<"������ñ��Ԫ�أ�";
	for(i=0;i<n;i++)
	{
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

void output(LinkList L)										//����������������ÿ��Ԫ��
{
	int i=0;
	LNode *p;
	p=L->next;
	while(p)
	{
		if(i)
			cout<<",";
		cout<<p->data;
		p=p->next;
		i=1;
	}
}

void LinkedListSelectSort(LinkList head)
 //���㷨һ���ҳ�һ���ؼ�����С�Ľ�㣬�����ݺ͵�ǰ�����н���;��Ҫ����ָ�룬
 //������µ�ǰ������С����ǰ��ָ��
{LinkList r,q,p=head->next; 
  int t;
  while(p!=NULL)
    {
	q=p->next;  
	r=p;     //��r��ָ��ؼ�����С�Ľ���ָ��
     while (q!=NULL)
      {
		  if(q->data<r->data)  
		  r=q;
		  q=q->next;
		 }
	     if(r!=p) 
		 { 
		 t=r->data;
		 r->data=p->data;
		 p->data=t;
		 }
    	p=p->next;
	 }
}
int main()
{
	LinkList L;
	int num;
	
	cout<<"�����뵥����Ԫ�ظ���n��";	
	cin>>num;	
	InitList_L(L);													//La��Ĵ���
	input(L,num);												//������������La����������
	

    LinkedListSelectSort(L);											//��������La��Lb���кϲ�
	
	
	cout<<"�����\n";			//����ϲ���ĵ�����Lc
	output(L);
	cout<<endl;
	return 0;
}
