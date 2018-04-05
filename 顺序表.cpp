#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
typedef double SNode;
typedef struct {
	SNode *base;
	SNode *top;
	int stacksize;
}sqStack;

Status InitStack(sqStack &S)
{
	S.base=new SNode[MAXSIZE]; 
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
Status Push(sqStack &S,SNode e){
	if(S.top-S.base==S.stacksize)
	return ERROR;
	*S.top++=e;
	return OK;
}
Status Pop(sqStack &S,SNode &e){
	if(S.base==S.top)
	return ERROR;
	e=*--S.top;
	return OK;
}
SNode GetTop(sqStack S){
	if(S.base!=S.top){
		return *(S.top-1);
		}
}
int main()
{
	sqStack S;
	SNode e1=100; 
	SNode e2=200;
	SNode e3; 
	InitStack(S);
	Push(S,e1);
	Push(S,e2);
	cout<<GetTop(S)<<endl;
	Pop(S,e3);
	cout<<e3<<endl;
	cout<<GetTop(S)<<endl;
}

