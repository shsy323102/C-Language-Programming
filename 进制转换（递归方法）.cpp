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
	cout<<"输入一个十进制数："<<endl;
	cin>>a;
	cout<<"要转化为多少进制数："<<endl;
	cin>>b;
	conversion(a,b);
}

