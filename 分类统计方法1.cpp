/*统计串S中字符的种类和个数*/
#include<cstring>
#include<iostream>
using namespace std;
void count()//统计输入字符串中数字字符和字母字符的个数。
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
	  cout<<"数字"<<i<<"的个数"<<num[i]<<endl;
  for(i=10;i<36;i++)   
    cout<<"字母"<<char(i+55)<<"的个数"<<num[i]<<endl;
}
int main()
{
	cout<<"请输入字符串:('#'结束)"; 
	count();
	return 0;
}


