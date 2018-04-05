/*统计串S中字符的种类和个数*/
#include<cstring>
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSTRLEN 255   		//用户可在255以内定义最长串长
//typedef char SString[MAXSTRLEN+1];		//0号单元存放串的长度
typedef struct{   
   char ch[MAXSTRLEN+1];				//若是非空串，则按串长分配存储区，否则ch为NULL   
   int length;				//串长度   
}SString; 
typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

void Select(HuffmanTree HT,int len,int &s1,int &s2)
{
	int i,min1=INT_MAX,min2=INT_MAX;//先赋予最大值
	for(i=1;i<=len;i++)
	{
		if(HT[i].weight<min1&&HT[i].parent==0)
		{
			min1=HT[i].weight;
			s1=i;
		}	
	}
	int temp=HT[s1].weight;//将原值存放起来，然后先赋予最大值，防止s1被重复选择
	HT[s1].weight=INT_MAX;
	for(i=1;i<=len;i++)
	{
		if(HT[i].weight<min2&&HT[i].parent==0)
		{
			min2=HT[i].weight;
			s2=i;
		}
	}
	HT[s1].weight=temp;//恢复原来的值
}

Status StrAssign(SString &T, char *chars) { //生成一个其值等于chars的串T
	int i;
	if (strlen(chars) > MAXSTRLEN)
		return ERROR;
	else {
		T.length = strlen(chars);
		for (i = 1; i <= T.length; i++)
			T.ch[i] = *(chars + i - 1);
		return OK;
	}
}
typedef struct {
     char ch;
     int num;
} mytype;
void StrAnalyze(mytype T[],SString S,int &count)//统计串S中字符的种类和个数
{
	char c;
 	int i,j;
	 for (i=0;i<=20;i++) T[i].ch='\0';
	  for(i=1;i<=S.length;i++)
	  {
	    c=S.ch[i];
		j=1;
	    while(T[j].ch&&T[j].ch!=c) j++; //查找当前字符c是否已记录过
	    if(T[j].ch) T[j].num++;
	    else {T[j].ch=c;T[j].num=0;}
	  }//for 
	  for(j=1;T[j].ch!=NULL;j++)
	  {
	  	 cout<<T[j].ch<<":"<<T[j].num<<endl;
	  }
	  count=j-1;
//	  
}//StrAnalyze
void CreatHuffmanTree(HuffmanTree &HT,mytype T[],int n)
{
	//构造赫夫曼树HT
	int m,s1,s2,i;
    if(n<=1) return;
	m=2*n-1;
	HT=new HTNode[m+1];  		//0号单元未用，所以需要动态分配m+1个单元，HT[m]表示根结点   
	for(i=1;i<=m;++i)        	//将1~m号单元中的双亲、左孩子，右孩子的下标都初始化为0   
	   { HT[i].parent=0;  HT[i].lchild=0;  HT[i].rchild=0; }
	for(i=1;i<=n;++i)        	//输入前n个单元中叶子结点的权值  
		HT[i].weight=T[i].num;  
	/*――――――――――初始化工作结束，下面开始创建赫夫曼树――――――――――*/ 
	for(i=n+1;i<=m;++i) 
	{  	//通过n-1次的选择、删除、合并来创建赫夫曼树
		Select(HT,i-1,s1,s2);
		//在HT[k](1≤k≤i-1)中选择两个其双亲域为0且权值最小的结点,
		// 并返回它们在HT中的序号s1和s2
		HT[s1].parent=i; 	
		HT[s2].parent=i;   
		//得到新结点i，从森林中删除s1，s2，将s1和s2的双亲域由0改为i
		HT[i].lchild=s1;   
		HT[i].rchild=s2 ;							//s1,s2分别作为i的左右孩子
		HT[i].weight=HT[s1].weight+HT[s2].weight; 	//i 的权值为左右孩子权值之和
	}												//for
}	
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
	//从叶子到根逆向求每个字符的赫夫曼编码，存储在编码表HC中
	int i,start,c,f;
	HC=new char*[n+1];         						//分配n个字符编码的头指针矢量
	char *cd=new char[n];							//分配临时存放编码的动态数组空间
	cd[n-1]='\0';                            		//编码结束符
	for(i=1;i<=n;++i)
	{                      							//逐个字符求赫夫曼编码
		start=n-1;                          		//start开始时指向最后，即编码结束符位置
		c=i; 
		f=HT[i].parent;                 			//f指向结点c的双亲结点
		while(f!=0)
		{                          					//从叶子结点开始向上回溯，直到根结点
			--start;                          		//回溯一次start向前指一个位置
			if(HT[f].lchild==c)  
				cd[start]='0';						//结点c是f的左孩子，则生成代码0
			else 
				cd[start]='1';                 		//结点c是f的右孩子，则生成代码1
			c=f; 
			f=HT[f].parent;             			//继续向上回溯
		}                                  			//求出第i个字符的编码      
		HC[i]=new char[n-start];         			// 为第i 个字符编码分配空间
		strcpy(HC[i], &cd[start]);        			//将求得的编码从临时空间cd复制到HC的当前行中
	}
	delete cd;                            			//释放临时空间
}
void show(mytype T[],HuffmanCode HC,int n)
{
	for(int i=1;i<=n;i++)
		cout<<T[i].ch<<"编码为"<<HC[i]<<endl;
}	
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	SString S;
	int count;
	char*T="sasdddasasdasdfewfras";
	StrAssign(S,T);
	mytype arr[20];
	StrAnalyze(arr,S,count);
	cout<<count<<endl;
	CreatHuffmanTree(HT,arr,count);
	CreatHuffmanCode(HT,HC,count);
	show(arr,HC,count);
	return 0;
//count();
}


