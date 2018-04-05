//�㷨7.4�������������ĵݹ����
//�㷨7.5�������������Ĳ���
//�㷨7.6�������������Ĵ���
//�㷨 7.7��������������ɾ��
#include<iostream>
using namespace std;
#define ENDFLAG -1

typedef struct BSTNode{
	char ch;     
	int count;    
	BSTNode *lchild,*rchild;	//���Һ���ָ��
}BSTNode,*BSTree;


//�㷨7.4�������������ĵݹ����
BSTree SearchBST(BSTree T,char key) {
  if((!T)|| key==T->ch) return T;       	            	//���ҽ���
  else if (key<T->ch)  return SearchBST(T->lchild,key);	//���������м�������
  else return SearchBST(T->rchild,key);    		   			//���������м�������
 	
} // SearchBST

void InsertBST(BSTree &T,char e ) {
	if(SearchBST(T,e)&&T){
		BSTree B = SearchBST(T,e);
		B->count++;
	}
	else {	
		  if(!T) {                				//�ҵ�����λ�ã��ݹ����
				 BSTree S = new BSTNode;            		//�����½��*S
		         S->ch = e;
				 S->count=1;                  		//�½��*S����������Ϊe   
		         S->lchild = S->rchild = NULL;	//�½��*S��ΪҶ�ӽ��
		         T =S;            				//���½��*S���ӵ����ҵ��Ĳ���λ��
		  }
		  else if (e< T->ch) 
		      InsertBST(T->lchild, e );			//��*S����������
		  else if (e> T->ch) 
		      InsertBST(T->rchild, e);
	}			//��*S����������
}// InsertBST



//�㷨7.6�������������Ĵ���
void CreateBST(BSTree &T ) {
  //���ζ���һ���ؼ���Ϊkey�Ľ�㣬���˽��������������T��
  T=NULL;
  char e;
  cin>>e;      
  while(e!='#'){   	//ENDFLAGΪ�Զ��峣������Ϊ���������־
    InsertBST(T,e);          	//���˽��������������T��
    cin>>e;			//???
  }           
}



void InOrderTraverse(BSTree &T)
{
	if(T)
	{
	InOrderTraverse(T->lchild);
	cout<<T->ch<<" "<<T->count<<endl;
	InOrderTraverse(T->rchild);
	}
}
int  main()
{
	BSTree T;
	cout<<"���ַ�����#�������룺"<<endl;
	CreateBST(T);
	InOrderTraverse(T);
	cout<<endl;
}

