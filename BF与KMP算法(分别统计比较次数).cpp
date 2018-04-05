/***字符串匹配算法***/
#include<cstring>
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSTRLEN 255   		//用户可在255以内定义最长串长
typedef struct {		//0号单元存放串的长度
 char ch[MAXSTRLEN+1];
 int length;
  }SString;
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
void num(SString T,int &n,int &i,int &j){	
	if(j>T.length){
		if(n==0){
		cout<<"主串和子串在第"<<i-T.length<<"个字符处首次匹配\n";
	}
		n++;
		j=1;
	}
}
void num2(SString T,int &n,int &i,int &j,int next[]){	
	if(j>T.length){
		if(n==0){
		cout<<"主串和子串在第"<<i-T.length<<"个字符处首次匹配\n";
	}
		n++;
		j=next[1];
	}
}
//填写4.1　BF算法 并增加计算比较次数 
void Index_BF(SString S, SString T, int pos,int &count,int &n)
{
	//返回模式T在主串S中第pos个字符之后第s一次出现的位置。若不存在，则返回值为0
	//其中，T非空，1≤pos≤StrLength(S)
	int i = pos;
	int j = 1;
	while(i<=S.length){
		if(S.ch[i]==T.ch[j]){
			i++;
			j++;
			count++;
			num(T,n,i,j);	
		}else {
			i=i-j+2;j=1;
			count++;
		}		
	}
	
}//Index
//算法4.3　计算next函数值
void get_next(SString T, int next[])
{ //求模式串T的next函数值并存入数组next
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length)
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
}//get_next

//算法4.2　KMP算法,增加计算比较次数
void Index_KMP(SString S, SString T, int pos, int next[],int &count,int &n)
{ 	// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，1≤pos≤StrLength(S)
	int i = pos, j = 1;
	while (i <= S.length)
	{	
	if (j == 0 || S.ch[i] == T.ch[j]) // 继续比较后继字
		{
			++i;
			++j;
			count++;
			num2(T,n,i,j,next);
		}
		else{
			j = next[j]; 
			count++;
		}
	}// 模式串向右移动
	 
}//Index_KMP
int main()
{
	SString S;
	StrAssign(S,"bbasbabasbababba") ;
	SString T;
	StrAssign(T,"sba");
	int count = 0;
	int n=0;
	cout<<"调用BF算法:"<<endl; 
	Index_BF(S,T,1,count,n);
	cout<<"比较的次数为"<<count<<endl;
	cout<<"主串中模式串总个数"<<n<<endl;
	int *p = new int[T.length+1]; // 生成T的next数组
	get_next(T,p);
	count = 0;
	n=0;
	cout<<"调用KMP算法:"<<endl;
	Index_KMP(S,T,1,p,count,n);
	cout<<"比较的次数为"<<count<<endl;
	cout<<"主串中模式串总个数"<<n<<endl;
	return 0;
}
