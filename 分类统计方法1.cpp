/*ͳ�ƴ�S���ַ�������͸���*/
#include<cstring>
#include<iostream>
using namespace std;
void count()//ͳ�������ַ����������ַ�����ĸ�ַ��ĸ�����
{ int i,num[36];
  char ch;
  for (i=0;i<36;i++) num[i]=0;
  while ((ch=getchar())!='#')
  {
  if('0'<=ch&&ch<='9') 
     {i=int(ch)-48;num[i]++;}
   else if('A'<=ch&&ch<='Z')
      {i=ch-65+10;num[i]++;}}
  for(i=0;i<10;i++)
	  cout<<"����"<<i<<"�ĸ���"<<num[i]<<endl;
  for(i=10;i<36;i++)   
    cout<<"��ĸ"<<char(i+55)<<"�ĸ���"<<num[i]<<endl;
}
int main()
{
	cout<<"�������ַ���:('#'����)"; 
	count();
	return 0;
}


