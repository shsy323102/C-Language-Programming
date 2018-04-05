//算法5.1 中序遍历的递归算法
#include<iostream>
using namespace std;
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct BiNode{				//二叉链表定义
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

/************************************* 队列 ***************************************/
typedef BiTree QElemType;

typedef struct{
	QElemType *base;//初始化时动态分配存储空间
	int front;//头指针
	int rear;//尾指针
}SqQueue;

//算法3.13　循环队列的初始化
Status InitQueue(SqQueue &Q)
{ // 构造一个空队列Q
	Q.base = new QElemType[MAXQSIZE];
	if(!Q.base)
	{
		return OVERFLOW;	// 存储分配失败
	}
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

//算法3.14　求循环队列的长度
int QueueLength(SqQueue Q)
{// 返回Q的元素个数，即队列的长度
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

//算法3.15　循环队列的入队
Status EnQueue(SqQueue &Q,QElemType e)
{// 插入元素e为Q的新的队尾元素
	if((Q.rear+1)%MAXQSIZE == Q.front)
	{
		return ERROR;//尾指针在循环意义上加1后等于头指针，表明队满
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return OK;
}

//算法3.16　循环队列的出队
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

//用算法5.3 先序遍历的顺序建立二叉链表
void CreateBiTree(BiTree &T){	
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//递归结束，建空树
	else{							
		T=new BiTNode;
		T->data=ch;					//生成根结点
		CreateBiTree(T->lchild);	//递归创建左子树
		CreateBiTree(T->rchild);	//递归创建右子树
	}								//else
}									//CreateBiTree

void InOrderTraverse(BiTree T){  
	//中序遍历二叉树T的递归算法
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

//实现按层遍历二叉树的非递归算法（队列）
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
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
    cout<<"中序遍历的结果为：\n";
	InOrderTraverse(tree);
	cout<<endl;
	//按层遍历二叉树
	cout<<"按层遍历的结果为：\n";
	HierarchyTraverse(tree);
	cout<<endl;
    cout<<"二叉树的宽度为:"<<endl<<width(tree)<<endl;
    return 0;
}


