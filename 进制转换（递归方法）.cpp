#include<iostream>
using namespace std;
void conversion (int a,int b) {
	if(a>0){
	conversion(a/b,b);
	}
	if(a%b!=0){
	cout<<a%b;
	}
}
int main()
{
	int a,b;
	cout<<"����һ��ʮ��������"<<endl;
	cin>>a;
	cout<<"Ҫת��Ϊ���ٽ�������"<<endl;
	cin>>b;
	conversion(a,b);
}

