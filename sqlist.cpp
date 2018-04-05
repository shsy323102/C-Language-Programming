#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define NOTFOUND 0
typedef int status;
typedef double ElemType;
typedef struct         
{
	ElemType *elem;
	int length;
}Sqlist;
status ListAll(Sqlist L){
	int i;
	if(L.length){
		for(i=0;i<L.length;i++){
			cout<<L.elem[i];
			cout<<" ";
		}
	}
	printf("\n");
	return OK;
}
status InitList(Sqlist &L){
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem){
	cout<<"储存分配失败"<<endl; 
	exit(OVERFLOW);
	}
	L.length=0;
	return OK;
}
status GetElem(Sqlist &L,int i,ElemType &e){
	if(i<0||i>L.length-1) return ERROR;
	e=L.elem[i];
	return OK;
}
status InsertElem(Sqlist &L,int i,ElemType &e){
	int j;
	if(i<0||i>L.length-1) return ERROR;
	for(j=L.length;j>i;j--){
		L.elem[j]=L.elem[j-1];
	}
	L.elem[i]=e;
	L.length++;
	return OK;
}
status DeleteElem(Sqlist &L,int i){
	int j;
	if(i<0||i>L.length-1) return ERROR;
	for(j=i;j<L.length-1;j++){
		L.elem[j]=L.elem[j+1];
	}
	L.length--;
	return OK;
}
status LocateElem(Sqlist L,ElemType e){
	int i;
	for(i=0;i<L.length-1;i++){
		if(e==L.elem[i]){
			return i;
		}
	}
	return NOTFOUND;
}
int main(){
	int i;
	Sqlist L;
	InitList(L);
	cout<<"输入10组数据:"<<endl;
	for(i=0;i<10;i++){
		cin>>L.elem[i];
		L.length++;
	}
	ListAll(L);
	ElemType e;	
	cout<<"输入要插入数据:"<<endl;
	cin>>e; 	
	cout<<"输入要插入数据角标:"<<endl;
	cin>>i; 
	InsertElem(L,i,e);
	ListAll(L);
	cout<<"输入要删除数据角标:"<<endl;
	cin>>i; 
	DeleteElem(L,i);
	ListAll(L);
	return 0;
} 
