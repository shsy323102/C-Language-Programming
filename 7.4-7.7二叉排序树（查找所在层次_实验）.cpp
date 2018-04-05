//�㷨7.4�������������ĵݹ����
//�㷨7.5�������������Ĳ���
//�㷨7.6�������������Ĵ���
//�㷨 7.7��������������ɾ��
#include<iostream>
using namespace std;
#define ENDFLAG -1
//char a[10]={'5','6','7','2','1','9','8','10','3','4','#'};//ȫ�ֱ���
typedef struct ElemType{	
	int  key;
}ElemType;

typedef struct BSTNode{
	ElemType data;	//���������
	BSTNode *lchild,*rchild;	//���Һ���ָ��
}BSTNode,*BSTree;


//�㷨7.4�������������ĵݹ����
BSTree SearchBST(BSTree T,int key,int &lev) {
	lev++;
  //�ڸ�ָ��T��ָ�����������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ��
  //�����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��
  if((!T)|| key==T->data.key) return T;       	            	//���ҽ���
  else if (key<T->data.key)  return SearchBST(T->lchild,key,lev);	//���������м�������
  else return SearchBST(T->rchild,key,lev);    		   			//���������м�������
 
} // SearchBST

//�ǵݹ�ʵ�ֲ��ҳɹ�ʱ����ָ�������Ԫ�ؽ���ָ������ڵĲ��
BSTree Searchlev(BSTree T,char key,int &lev) {
 	while(T!=NULL){	
	 	lev++;	
 		if(key<T->data.key)	{
 			T=T->lchild;
		 }	
		else if(key>T->data.key){
			T=T->rchild;
		}
		else {
			return T;
		}
	 }
	 return T;
}// Searchlev
//�㷨7.5�������������Ĳ���
void InsertBST(BSTree &T,ElemType e ) {
  //������������T�в����ڹؼ��ֵ���e.key������Ԫ��ʱ��������Ԫ��
  if(!T) {                				//�ҵ�����λ�ã��ݹ����
		 BSTree S = new BSTNode;            		//�����½��*S
         S->data = e;                  		//�½��*S����������Ϊe   
         S->lchild = S->rchild = NULL;	//�½��*S��ΪҶ�ӽ��
         T =S;            				//���½��*S���ӵ����ҵ��Ĳ���λ��
  }
  else if (e.key< T->data.key) 
      InsertBST(T->lchild, e );			//��*S����������
  else if (e.key> T->data.key) 
      InsertBST(T->rchild, e);			//��*S����������
}// InsertBST



//�㷨7.6�������������Ĵ���
void CreateBST(BSTree &T ) {
  //���ζ���һ���ؼ���Ϊkey�Ľ�㣬���˽��������������T��
  T=NULL;
  ElemType e;
  cin>>e.key;        //???
  while(e.key!=ENDFLAG){   	//ENDFLAGΪ�Զ��峣������Ϊ���������־
    InsertBST(T, e);          	//���˽��������������T��
    cin>>e.key;			//???
  }//while            
}//CreatBST

void DeleteBST(BSTree &T,int key) {
  //�Ӷ���������T��ɾ���ؼ��ֵ���key�Ľ��
  BSTree p=T;BSTree f=NULL;                     			//��ʼ��
  BSTree q;
  BSTree s;
  /*------------�����whileѭ���Ӹ���ʼ���ҹؼ��ֵ���key�Ľ��*p-------------*/
  while(p){                  
   if (p->data.key == key) break;  	      	//�ҵ��ؼ��ֵ���key�Ľ��*p������ѭ��
   f=p;                                			//*fΪ*p��˫�׽��
   if (p->data.key> key)  p=p->lchild;     	//��*p���������м�������
   else p=p->rchild;  	                  		//��*p���������м�������
  }//while
if(!p) return;                         		//�Ҳ�����ɾ����򷵻�
/*�D�����������ʵ��p��ָ�����ڲ��Ĵ���*p�������������ա��������������������D*/
if ((p->lchild)&& (p->rchild)) {     		//��ɾ���*p��������������
     q = p;
	 s = p->lchild;
     while (s->rchild)                			//��*p���������м���������ǰ����㣬�������½��
       {q = s; s = s->rchild;}	         		//���ҵ���ͷ
     p->data = s->data;               			//sָ��ɾ���ġ�ǰ����
     if(q!=p){
		 q->rchild = s->lchild;     	//�ؽ�*q��������
	 }
     else q->lchild = s->lchild;        		//�ؽ�*q��������
     delete s;
  }//if
else{
	if(!p->rchild) {               		//��ɾ���*p����������ֻ���ؽ���������
		  q = p; p = p->lchild; 
	  }//else if
	else if(!p->lchild) {               		//��ɾ���*p����������ֻ���ؽ���������
		 q = p; p = p->rchild;
	  }//else if
	/*�D�D�D�D�D�D�D�D�D�D��p��ָ�������ҽӵ���˫�׽��*f��Ӧ��λ�èD�D�D�D�D�D�D�D*/
	  if(!f) T=p;                       			//��ɾ���Ϊ�����
	  else if (q==f->lchild) f->lchild = p;   	//�ҽӵ�*f��������λ��
	  else f->rchild = p;                 		//�ҽӵ�*f��������λ��
	  delete q;
	}
}//DeleteBST

//�㷨 7.7��������������ɾ��

//�������
void InOrderTraverse(BSTree &T)
{
	if(T)
	{
	InOrderTraverse(T->lchild);
	cout<<T->data.key<<" "  ;
	InOrderTraverse(T->rchild);
	}
}
 char predt=0;
void judgeBST(BSTree &T,BSTree preT,int &m)
{
	if(m==0)return;
	if(T){
		judgeBST(T->lchild,T,m);
		if(preT->lchild==T){
			if(T->data.key>preT->data.key){
				m=0;
			}
		}
		else {
			if(T->data.key<preT->data.key){
				m=0;
			}
		}
		judgeBST(T->rchild,T,m);	
	}
}
int  main()
{
	BSTree T;int lev=0;
	cout<<"�����������������ÿո�ֿ�����-1��������"<<endl;
	CreateBST(T);
	cout<<"��ǰ�������������������Ϊ"<<endl;
	InOrderTraverse(T);
	cout<<endl;
	int key;//�����һ��ɾ������
	cout<<"����������ҹؼ��֣�������"<<endl;
	cin>>key;
//	BSTree result=SearchBST(T,key,lev);
	BSTree result=Searchlev(T,key,lev);
	if(result)
	{cout<<"�ҵ��ؼ���"<<key<<"��"<<lev<<"��"<<endl;}
	else
	{cout<<"δ�ҵ�"<<key<<endl;}
	//Searchpath( T, key);cout<<endl;
	cout<<"�������ɾ���Ĺؼ���"<<endl;
	cin>>key;
	DeleteBST(T,key);
	cout<<"��ǰ�������������������Ϊ"<<endl;
	InOrderTraverse(T);
	cout<<endl;
	BSTree Y = new BSTNode; 
	Y->data.key=3;
	BSTree L = new BSTNode; 
	L->data.key=4;
	L->lchild = L->rchild = NULL;
	Y->lchild=L;
	BSTree R = new BSTNode; 
	R->data.key=5;
	R->lchild = R->rchild = NULL;
	Y->rchild=R;
	BSTree R2 = new BSTNode; 
	R2->data.key=6;
	R2->lchild = R2->rchild = NULL;
	R->rchild=R2;
	InOrderTraverse(Y);
	int m=1;
	judgeBST(Y,Y,m);
if(m) 
    cout<<" ��һ��������"<<endl;
else 
   cout<<" ����һ��������"<<endl;
    return 1;
}

