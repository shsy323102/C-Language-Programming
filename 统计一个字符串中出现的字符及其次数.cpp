//算法7.4　二叉排序树的递归查找
//算法7.5　二叉排序树的插入
//算法7.6　二叉排序树的创建
//算法 7.7　二叉排序树的删除
#include<iostream>
using namespace std;
#define ENDFLAG -1

typedef struct BSTNode{
	char ch;     
	int count;    
	BSTNode *lchild,*rchild;	//左右孩子指针
}BSTNode,*BSTree;


//算法7.4　二叉排序树的递归查找
BSTree SearchBST(BSTree T,char key) {
  if((!T)|| key==T->ch) return T;       	            	//查找结束
  else if (key<T->ch)  return SearchBST(T->lchild,key);	//在左子树中继续查找
  else return SearchBST(T->rchild,key);    		   			//在右子树中继续查找
 	
} // SearchBST

void InsertBST(BSTree &T,char e ) {
	if(SearchBST(T,e)&&T){
		BSTree B = SearchBST(T,e);
		B->count++;
	}
	else {	
		  if(!T) {                				//找到插入位置，递归结束
				 BSTree S = new BSTNode;            		//生成新结点*S
		         S->ch = e;
				 S->count=1;                  		//新结点*S的数据域置为e   
		         S->lchild = S->rchild = NULL;	//新结点*S作为叶子结点
		         T =S;            				//把新结点*S链接到已找到的插入位置
		  }
		  else if (e< T->ch) 
		      InsertBST(T->lchild, e );			//将*S插入左子树
		  else if (e> T->ch) 
		      InsertBST(T->rchild, e);
	}			//将*S插入右子树
}// InsertBST



//算法7.6　二叉排序树的创建
void CreateBST(BSTree &T ) {
  //依次读入一个关键字为key的结点，将此结点插入二叉排序树T中
  T=NULL;
  char e;
  cin>>e;      
  while(e!='#'){   	//ENDFLAG为自定义常量，作为输入结束标志
    InsertBST(T,e);          	//将此结点插入二叉排序树T中
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
	cout<<"请字符串以#结束输入："<<endl;
	CreateBST(T);
	InOrderTraverse(T);
	cout<<endl;
}

