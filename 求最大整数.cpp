#include<iostream>
using namespace std;
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define NOTFOUND -3
typedef int status;
typedef double ElemType;
typedef struct Lnode     
{
	ElemType data;
	struct Lnode *next;
}Lnode,*LinkList;
status InitList(LinkList &L){
	L=new Lnode;
	L->data=0;
	L->next=NULL;
	return OK; 
}
LinkList createList(){
		int i; 
		ElemType data;
		LinkList L = new Lnode;
		L->data=0;
		LinkList R = new Lnode;
		R=L;
		cout<<"请输入10个数据："<<endl; 
		for(i=0;i<10;i++){
		LinkList N = new Lnode;
			cin>>data;
			N->data=data;
			N->next=NULL;
			R->next=N;
			R=N;
			L->data++;
		}
		R->next=NULL;
		return L;
}
status ListAll(LinkList &L){
		LinkList P = new Lnode;
		P=L->next;
		while(P!=NULL){
			cout<<P->data<<endl;
			P=P->next;
		}
		return OK;
}
status InsertElem(LinkList &L,int i,ElemType &e){
	if(i<0||i>L->data-1)
	return ERROR;
	LinkList P = L;
	int j;
	for(j=0;j<i;j++){
		P=P->next;
	}
	LinkList R = new Lnode;
	R->data=e;
	R->next=P->next;
	P->next=R;
	L->data++;
	return OK;
}
status DeleteElem(LinkList &L,int i){
	if(i<0||i>L->data-1)
	return ERROR;
	LinkList P = L;
	int j;
	for(j=0;j<i;j++){
		P=P->next;
	}
	LinkList Q = P->next;
	P->next=Q->next;
	delete Q;
	L->data--;
	return OK;
}
status LocateElem(LinkList &L,ElemType &e){
	LinkList P = L->next;
	int j=0;
	while(P!=NULL){
		if(P->data==e){
			return j;
		}
		P=P->next;
		j++;
	}
	return NOTFOUND;
}
void max(LinkList &L,ElemType &e){
	if(L!=NULL){
		if(e<L->data){
			e=L->data;
		}
		max(L->next,e);
	}
}
int main(){
	int i;
	LinkList L=createList();
	ListAll(L);
	L=L->next;
	ElemType e = L->data;
	max(L,e);
	cout<<"最大值为"<<e<<endl;
} 
