#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define NOTFOUND -3
typedef int status;
typedef double ElemType;
typedef struct Dulnode       
{
	ElemType data;
	Dulnode *prior;
	Dulnode *next;
}Dulnode,*Dulinklist;
status ListAll1(Dulinklist L){
	Dulinklist P=L->next;
	while(P!=NULL){
		cout<<P->data<<endl;
		P=P->next;
	}
}
status ListAll(Dulinklist L){
	Dulinklist P=L->next;
	while(P->next!=NULL){
		P=P->next;
	}
	while(P->prior!=NULL){
		cout<<P->data<<endl;
		P=P->prior;
	}
}
status InitList(Dulinklist &L){
	L= new Dulnode;
	L->data=0;
	L->next=NULL;
	L->prior=NULL;
	return OK;
}
Dulinklist createList(){
	int i;
	Dulinklist L;
	InitList(L);
	Dulinklist P=L;
	for(i=0;i<10;i++){
		Dulinklist N = new Dulnode;
		N->data=i;
		N->prior=P;
		P->next=N;
		P=N;
		L->data++;
	}
	P->next=NULL;
	return L;
}
status InsertElem(Dulinklist &L,int i,ElemType &e){
	int j;
	Dulinklist P=L;
	if(i<0||i>L->data-1)
	return ERROR;
	for(j=0;j<i;j++){
		P=P->next;
	}
		Dulinklist N = new Dulnode;
	N->data=e;
	N->next=P->next;
	P->next->prior=N;
	N->prior=P;
	P->next=N;
	return OK;
}
status DeleteElem(Dulinklist &L,int i){
	int j;
	Dulinklist P=L;
	if(i<0||i>L->data-1)
	return ERROR;
	for(j=0;j<i;j++){
		P=P->next;
	}
	Dulinklist Q=P->next;
	P->next=Q->next;
	Q->next->prior=P;
	delete Q;
}

int main(){
	ElemType e =100;
	Dulinklist L=createList();
	InsertElem(L,2,e);
	DeleteElem(L,2);
	ListAll(L);
	cout<<L->data<<endl;
} 
