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


void fun (LinkStack &S) {
	char a[10];
	int i;
	int sum;
	int e1,e2;
	while(true){
	sum=0;
	i=0;
	scanf("%s",a);
	switch(a[0]){
		case '$':Pop(S,e1);printf("%d",e1);return;
		case '+':Pop(S,e1);Pop(S,e2);Push(S,e2+e1);break;
		case '-':Pop(S,e1);Pop(S,e2);Push(S,e2-e1);break;
		case '*':Pop(S,e1);Pop(S,e2);Push(S,e2*e1);break;
		case '/':Pop(S,e1);Pop(S,e2);Push(S,e2/e1);break;
		default:
				while(a[i]!='\0'){
				sum=sum*10+a[i]-'0';
				i++;
			}
			Push(S,sum);
		}	
	}
 } 

int main()
{
	LinkStack S;
	InitStack(S);
	fun(S);
	return 0;
}

