/*ͳ�ƴ�S���ַ�������͸���*/
#include<cstring>
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSTRLEN 255   		//�û�����255���ڶ��������
//typedef char SString[MAXSTRLEN+1];		//0�ŵ�Ԫ��Ŵ��ĳ���
typedef struct{   
   char ch[MAXSTRLEN+1];				//���Ƿǿմ����򰴴�������洢��������chΪNULL   
   int length;				//������   
}SString; 
Status StrAssign(SString &T, char *chars) { //����һ����ֵ����chars�Ĵ�T
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
void StrAnalyze(SString S)//ͳ�ƴ�S���ַ�������͸���
{
	char c;
  	mytype T[20]; //�ýṹ����T�洢ͳ�ƽ��
 	int i,j;
	 for (i=0;i<=20;i++) T[i].ch='\0';
	  for(i=1;i<=S.length;i++)
	  {
	    c=S.ch[i];
		j=0;
	    while(T[j].ch&&T[j].ch!=c) j++; //���ҵ�ǰ�ַ�c�Ƿ��Ѽ�¼��
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


