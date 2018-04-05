#include<iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef struct BTNode{
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
	int count;
}BTNode,*BITree;
typedef struct Stacknode{
	struct BTNode *node;
	struct Stacknode *next;
}Stacknode,*Linkstack;
int Initstack(Linkstack &S){
	S=NULL;
	return OK;
}
int Push(Linkstack &S,BITree e){
	Linkstack p;
	p=new Stacknode;
	p->node=e;
	p->next=S;
	S=p;
	return OK;
}
int Pop(Linkstack &S,BITree &e){
	Linkstack p;
	if(S==NULL)
		return ERROR;
	e=S->node;
	p=S;
	S=S->next;
	delete p;
	return OK;
}
int StackEmpty(Linkstack S){
	if(S==NULL)
		return 1;
	else
		return 0;
}
void CreateBitree(BITree &T){
	char ch;
	cin>>ch;
	if(ch=='#')
		T=NULL;
	else
	{
		T=new BTNode;
		T->data=ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}
/*void Preorder(BITree &T){
	Linkstack S;
	BITree p1,q;
	Initstack(S);
	p1=T;
	while(p1||!StackEmpty(S))
	{
		if(p1)
		{
			cout<<p1->data;
			Push(S,p1);
			p1=p1->lchild;
		}
		else
		{
			q=new BTNode;
			Pop(S,q);
			p1=q->rchild;
		}
	}
}*/
void Inorder(BITree &T){
	BITree p1=new BTNode;
	BITree q=new BTNode;
	Linkstack S;
	Initstack(S);
	p1=T;
	while(p1||!StackEmpty(S))
	{
		if(p1)
		{
			Push(S,p1);
			p1=p1->lchild;
		}
		else
		{
			Pop(S,q);
			cout<<q->data<<endl;
			p1=q->rchild;
		}
	}
}
void Postorder(BITree &T){
	BITree p1;
	Linkstack S;
	Initstack(S);
	p1=T;
	while(p1||!StackEmpty(S))
	{
		if(p1)
		{
			if(p1->count!=2)
			{
				Push(S,p1);
				p1->count=1;
			}
			p1=p1->lchild;
		}
		else
		{
			Pop(S,p1);
			if(p1->count==2)
				cout<<p1->data;
			else
			{
				p1->count++;
				Push(S,p1);
			}
			p1=p1->rchild;
		}
	}
}
void InOrderTraverse(BITree T){  
	//中序遍历二叉树T的递归算法
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
int main(){
	BITree T;
	CreateBitree(T);
	InOrderTraverse(T); 
	/*cout<<"先序遍历"<<endl;
	Preorder(T);
	cout<<endl;*/
	cout<<"中序遍历"<<endl;
	Inorder(T);
	cout<<endl;
//	cout<<"后序遍历"<<endl;
//	Postorder(T);
//	cout<<endl;
}
				
			





