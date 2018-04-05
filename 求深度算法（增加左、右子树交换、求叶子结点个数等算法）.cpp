//�㷨5.5 ��������������
#include<iostream>
using namespace std;

//�������Ķ�������洢��ʾ
typedef struct BiNode
{				
	char data;						//���������
	struct BiNode *lchild,*rchild;	//���Һ���ָ��
}BiTNode,*BiTree;

//���㷨5.3������������
void CreateBiTree(BiTree &T)
{	
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

int Depth(BiTree T)
{ 
	int m,n;
	if(T == NULL ) return 0;        //����ǿ��������Ϊ0���ݹ����
	else 
	{							
		m=Depth(T->lchild);			//�ݹ��������������ȼ�Ϊm
		n=Depth(T->rchild);			//�ݹ��������������ȼ�Ϊn
		if(m>n) return(m+1);		//�����������Ϊm ��n�Ľϴ��߼�1
		else return (n+1);
	}
}
void InOrderTraverse(BiTree T){  
	//�������������T�ĵݹ��㷨
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
ChangeLR1(BiTree &T)
{
 if(T){
 	BiTree N=new BiTNode;
 	N=T->rchild;
 	T->rchild=T->lchild;
 	T->lchild=N;
 	ChangeLR1(T->lchild);
 	ChangeLR1(T->rchild);
 }
}
ChangeLR2(BiTree &T)
{
 if(T){
 	ChangeLR2(T->lchild);
 	BiTree N=new BiTNode;
 	N=T->rchild;
 	T->rchild=T->lchild;
 	T->lchild=N;
 	ChangeLR2(T->rchild);
 }
}
ChangeLR3(BiTree &T)
{
 if(T){
 	ChangeLR3(T->lchild);
 	ChangeLR3(T->rchild);
 	BiTree N=new BiTNode;
 	N=T->rchild;
 	T->rchild=T->lchild;
 	T->lchild=N;
 }
}


int main()
{
	BiTree tree;
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
	cout<<"�������Ϊ��"<<Depth(tree)<<endl;
	cout<<"��������Ľ��Ϊ��\n";
	InOrderTraverse(tree);
	cout<<endl; 
	ChangeLR1(tree);
	cout<<"��������������Ľ��Ϊ��\n";
	InOrderTraverse(tree);
	cout<<endl; 
	ChangeLR2(tree);
    cout<<"��������������Ľ��Ϊ��\n";
    InOrderTraverse(tree);
    cout<<endl; 
    ChangeLR3(tree);
    cout<<"��������������Ľ��Ϊ��\n";
    InOrderTraverse(tree);
    return 0; 
}
