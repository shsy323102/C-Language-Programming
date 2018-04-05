#include<iostream>
using namespace std;

typedef struct LNode										//定义单链表
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void InitList_L(LinkList &L)								//创建单链表
{
	L=new LNode;
	L->next=NULL;
}

void input(LinkList &L,int n)								//依次往单链表L里输入数据
{
	int i;
	LinkList p,r;
	r=L;
	cout<<"请输入该表的元素：";
	for(i=0;i<n;i++)
	{
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

void output(LinkList L)										//依次输出单链表里的每个元素
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
 //本算法一趟找出一个关键字最小的结点，其数据和当前结点进行交换;若要交换指针，
 //则须记下当前结点和最小结点的前驱指针
{LinkList r,q,p=head->next; 
  int t;
  while(p!=NULL)
    {
	q=p->next;  
	r=p;     //设r是指向关键字最小的结点的指针
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
	
	cout<<"请输入单链表元素个数n：";	
	cin>>num;	
	InitList_L(L);													//La表的创建
	input(L,num);												//依次往单链表La里输入数据
	

    LinkedListSelectSort(L);											//将单链表La和Lb进行合并
	
	
	cout<<"排序后：\n";			//输出合并后的单链表Lc
	output(L);
	cout<<endl;
	return 0;
}
