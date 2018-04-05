/***链栈实现数制的转换***/
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct SNode{
	int data;
	struct SNode *next;
}SNode,*LinkStack;

Status InitStack(LinkStack &S)
{
	S = NULL; 
	return OK;
}
bool StackEmpty(LinkStack S)
{
	if(!S)
		return true;
	return false;
}
Status Push(LinkStack &S,int e)
{
	SNode *p = new SNode;
	if(!p)
	{
		return OVERFLOW;
	} 
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(LinkStack &S,int &e)
{
	SNode *p;                                                  
	if(!S)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}

//算法3.8　数制的转换(链栈实现)
void conversion (LinkStack &S,int &b,int &a) {
	int e; 
	while(a>0){
		Push(S,a%b);
		a=a/b;
	}
	while(!StackEmpty(S)){
		Pop(S,e);
		cout<<e;
	}
}
int main()
{
	int a;
	int b; 
	cout<<"输入一个十进制数："<<endl;
	cin>>a;
	cout<<"要转化为多少进制数："<<endl;
	cin>>b;
	LinkStack S;
	InitStack(S);
	conversion(S,b,a);
	return 0;
}

