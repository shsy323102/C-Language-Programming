#include<iostream>
using namespace std;
int n;
void fun(int a[],int p[]){
	int i,j;
	int count;
	for(i=0;i<n;i++){
		for(count=0,j=0;j<n;j++){
			if(a[j]<a[i]&&i!=j){
				count++;
			}
		}
		p[count]=a[i];
	}
}
int main()
{
	int i;
	cout<<"输入数组大小："<<endl;
	cin>>n;
	int a[n],p[n];
	cout<<"输入数组元素："<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	fun(a,p);
	for(i=0;i<n;i++){
		cout<<p[i]<<"  ";
	}
	return 0;
}
