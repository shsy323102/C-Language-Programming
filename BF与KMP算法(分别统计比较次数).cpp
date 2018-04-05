/***�ַ���ƥ���㷨***/
#include<cstring>
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSTRLEN 255   		//�û�����255���ڶ��������
typedef struct {		//0�ŵ�Ԫ��Ŵ��ĳ���
 char ch[MAXSTRLEN+1];
 int length;
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
void num(SString T,int &n,int &i,int &j){	
	if(j>T.length){
		if(n==0){
		cout<<"�������Ӵ��ڵ�"<<i-T.length<<"���ַ����״�ƥ��\n";
	}
		n++;
		j=1;
	}
}
void num2(SString T,int &n,int &i,int &j,int next[]){	
	if(j>T.length){
		if(n==0){
		cout<<"�������Ӵ��ڵ�"<<i-T.length<<"���ַ����״�ƥ��\n";
	}
		n++;
		j=next[1];
	}
}
//��д4.1��BF�㷨 �����Ӽ���Ƚϴ��� 
void Index_BF(SString S, SString T, int pos,int &count,int &n)
{
	//����ģʽT������S�е�pos���ַ�֮���sһ�γ��ֵ�λ�á��������ڣ��򷵻�ֵΪ0
	//���У�T�ǿգ�1��pos��StrLength(S)
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
//�㷨4.3������next����ֵ
void get_next(SString T, int next[])
{ //��ģʽ��T��next����ֵ����������next
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

//�㷨4.2��KMP�㷨,���Ӽ���Ƚϴ���
void Index_KMP(SString S, SString T, int pos, int next[],int &count,int &n)
{ 	// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	//���У�T�ǿգ�1��pos��StrLength(S)
	int i = pos, j = 1;
	while (i <= S.length)
	{	
	if (j == 0 || S.ch[i] == T.ch[j]) // �����ȽϺ����
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
	}// ģʽ�������ƶ�
	 
}//Index_KMP
int main()
{
	SString S;
	StrAssign(S,"bbasbabasbababba") ;
	SString T;
	StrAssign(T,"sba");
	int count = 0;
	int n=0;
	cout<<"����BF�㷨:"<<endl; 
	Index_BF(S,T,1,count,n);
	cout<<"�ȽϵĴ���Ϊ"<<count<<endl;
	cout<<"������ģʽ���ܸ���"<<n<<endl;
	int *p = new int[T.length+1]; // ����T��next����
	get_next(T,p);
	count = 0;
	n=0;
	cout<<"����KMP�㷨:"<<endl;
	Index_KMP(S,T,1,p,count,n);
	cout<<"�ȽϵĴ���Ϊ"<<count<<endl;
	cout<<"������ģʽ���ܸ���"<<n<<endl;
	return 0;
}
