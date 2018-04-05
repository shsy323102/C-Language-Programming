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
		LinkList L = new Lnode;
		L->data=0;
		LinkList R = new Lnode;
		R=L;
		ElemType e;
		cout<<"输入10组数据："<<endl;
			
		for(i=0;i<10;i++){
		LinkList N = new Lnode;
			cin>>e;
			N->data=e;
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
			cout<<P->data;
			cout<<" ";
			P=P->next;
		}
		printf("\n");
		return OK;
}
LinkList DaoXun(LinkList &L){
	LinkList P = new Lnode;
	LinkList Q = new Lnode;
	InitList(P);
	Q=L->next;
	while(Q!=NULL){
		LinkList R = new Lnode;
		R->data=Q->data;
		R->next=P->next;
		P->next=R;
		Q=Q->next;
		P->data++;
	}
	return P;
}
status List(LinkList &L){
	if(L->next!=NULL){
		List(L->next);
	}
	cout<<L->data<<endl;
}
ElemType FindMax(LinkList &L){
		LinkList Q = new Lnode;
		Q=L->next;
		ElemType max = Q->data;
		while(Q!=NULL){
			if(max<Q->data){
				max=Q->data;
			}
			Q=Q->next;
		}
		return max;
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
int main(){
	int i;
	LinkList L=createList();
	ListAll(L);
	ElemType e;
	cout<<"输入要插入角标和数据："<<endl;
	cin>>i;
	cin>>e;	
	InsertElem(L,i,e);
	ListAll(L);
	cout<<"输入要删除角标："<<endl;
	cin>>i;
	DeleteElem(L,i);
	ListAll(L);
	LinkList P = DaoXun(L);
	cout<<"倒序后的结果："<<endl;
	ListAll(P);
	cout<<"最大值为："<<FindMax(L)<<endl;
} 
