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
void StrAnalyze(SString S)//统计串S中字符的种类和个数
{
	char c;
  	mytype T[20]; //用结构数组T存储统计结果
 	int i,j;
	 for (i=0;i<=20;i++) T[i].ch='\0';
	  for(i=1;i<=S.length;i++)
	  {
	    c=S.ch[i];
		j=0;
	    while(T[j].ch&&T[j].ch!=c) j++; //查找当前字符c是否已记录过
	    if(T[j].ch) T[j].num++;
	    else {T[j].ch=c;T[j].num=0;}
	  }//for 
	  for(j=0;T[j].ch;j++)
	   cout<<T[j].ch<<":"<<T[j].num<<endl;
}//StrAnalyze

int main()
{
SString S;
	char*T="sasdddas1111as";
	StrAssign(S,T);
	StrAnalyze(S);
//count();
}


