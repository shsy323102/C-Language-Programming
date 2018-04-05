//�㷨5.1 ��������ĵݹ��㷨
#include<iostream>
using namespace std;
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct BiNode{				//����������
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

/************************************* ���� ***************************************/
typedef BiTree QElemType;

typedef struct{
	QElemType *base;//��ʼ��ʱ��̬����洢�ռ�
	int front;//ͷָ��
	int rear;//βָ��
}SqQueue;

//�㷨3.13��ѭ�����еĳ�ʼ��
Status InitQueue(SqQueue &Q)
{ // ����һ���ն���Q
	Q.base = new QElemType[MAXQSIZE];
	if(!Q.base)
	{
		return OVERFLOW;	// �洢����ʧ��
	}
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

//�㷨3.14����ѭ�����еĳ���
int QueueLength(SqQueue Q)
{// ����Q��Ԫ�ظ����������еĳ���
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

//�㷨3.15��ѭ�����е����
Status EnQueue(SqQueue &Q,QElemType e)
{// ����Ԫ��eΪQ���µĶ�βԪ��
	if((Q.rear+1)%MAXQSIZE == Q.front)
	{
		return ERROR;//βָ����ѭ�������ϼ�1�����ͷָ�룬��������
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return OK;
}

//�㷨3.16��ѭ�����еĳ���
Status DeQueue(SqQueue &Q,QElemType &e)
{
	if(Q.rear == Q.front)
	{
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return OK;
}

/************************************************************************************/

//���㷨5.3 ���������˳������������
void CreateBiTree(BiTree &T){	
	//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//�ݹ������������
	else{							
		T=new BiTNode;
		T->data=ch;					//���ɸ����
		CreateBiTree(T->lchild);	//�ݹ鴴��������
		CreateBiTree(T->rchild);	//�ݹ鴴��������
	}								//else
}									//CreateBiTree

void InOrderTraverse(BiTree T){  
	//�������������T�ĵݹ��㷨
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

//ʵ�ְ�������������ķǵݹ��㷨�����У�
void HierarchyTraverse(BiTree T)
{
	BiTree bt = T;
	SqQueue Q;
	InitQueue(Q);
	if(!bt){
		return;
	}
	EnQueue(Q,bt);
	while(Q.rear!=Q.front){
			DeQueue(Q,bt);
		cout<<bt->data;
		if(bt->lchild!=NULL){
			EnQueue(Q,bt->lchild);
		}
		if(bt->rchild!=NULL){
			EnQueue(Q,bt->rchild);
		}
	}
}
int height(BiTree T){
	int m,n;
	if(T==NULL){
	return 0;
	}
	m=height(T->lchild);
	n=height(T->rchild);
	return m>n ? m+1 : n+1 ; 
}
int width(BiTree T){
	BiTree bt = T;
	SqQueue Q;
	InitQueue(Q);
	if(!bt){
		return 0;
	}
	int cwidth,lwidth,max;
	EnQueue(Q,bt);
	lwidth=max=1;
		while(Q.rear!=Q.front){
			cwidth=lwidth;
			while(lwidth!=0){
				DeQueue(Q,bt);
				if(bt->lchild!=NULL){
					EnQueue(Q,bt->lchild);
				}
				if(bt->rchild!=NULL){
					EnQueue(Q,bt->rchild);
				}
				lwidth--;
			}
			cwidth=QueueLength(Q);
			max = max > cwidth ? max : cwidth;
			lwidth=cwidth;
		}
	return max;
}
int  main(){
	BiTree tree;
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
    cout<<"��������Ľ��Ϊ��\n";
	InOrderTraverse(tree);
	cout<<endl;
	//�������������
	cout<<"��������Ľ��Ϊ��\n";
	HierarchyTraverse(tree);
	cout<<endl;
    cout<<"�������Ŀ��Ϊ:"<<endl<<width(tree)<<endl;
    return 0;
}


