#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _data{
	long long id;
	char name[5];
	char sex[3];
	int old;
	char school[100];
	int payment;
	char address[100];
	char tel[12];
	struct _data* next;
} data;

data* creat(){
	FILE* fp;
	fp=fopen("data.txt","a");
	data* head=NULL;
	data* p;
	data* end=NULL;
	int i=1;
	char work;
	do{
		p=(data*)malloc(sizeof(data));
		printf("�������%d��ְ����Ϣ��\n",i++);
		printf("\t������ְ���ţ�");
		scanf("%lld",&p->id);
		
		if(p->id!=0){
			
			printf("\t������������");
			scanf("%s",&p->name);
			printf("\t�������Ա�");
			scanf("%s",&p->sex);
			printf("\t���������䣺");
			scanf("%d",&p->old);
			printf("\t������ѧ����");
			scanf("%s",&p->school);
			printf("\t�����빤�ʣ�");
			scanf("%d",&p->payment);
			printf("\t������סַ��");
			scanf("%s",&p->address);
			printf("\t������绰��");
			scanf("%s",&p->tel);
			
				fprintf(fp,"%lld ",p->id);
				fprintf(fp,"%s ",p->name);
				fprintf(fp,"%s ",p->sex);
				fprintf(fp,"%d ",p->old);
				fprintf(fp,"%s ",p->school);
				fprintf(fp,"%d ",p->payment);
				fprintf(fp,"%s ",p->address);
				fprintf(fp,"%s\n",p->tel);
			
			fclose(fp);
			if(head==NULL) head=p;
			if(end!=NULL) end->next=p;
			end=p;
		}
		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	}while(p->id!=0);
	if(end!=NULL) end->next=NULL;
	return head;
}
void list(){
	data a[1000];
	FILE* fp;
	fp=fopen("data.txt","r");
		long long id;
		char name[5];
		char sex[3];
		int old;
		char school[100];
		int payment;
		char address[100];
		char tel[12];
		int i=0;
	while(fscanf(fp,"%lld%s%s%d%s%d%s%s",&id,name,sex,&old,school,&payment,address,tel) ==8){
		a[i].id=id;
		strcpy(a[i].name,name);
		strcpy(a[i].sex,sex);
		a[i].old=old;
		strcpy(a[i].school,school);
		a[i].payment=payment;
		strcpy(a[i].address,address);
		strcpy(a[i].tel,tel);
		i++;
		printf("��%d��ְ����Ϣ���£�\n\tְ���ţ�%lld\n\t������%s\n\t�Ա�%s\n\t���䣺%d\n\tѧ����%s\n\t���ʣ�%d\n\tסַ��%s\n\t�绰��%s\n",i++,id,name,sex,old,school,payment,address,tel);	
	}
 } 
data* select(int n){
	FILE *fp;
	fp=fopen("data.txt","r");
	int i=0;
	data a[1000];
		long long id;
		char name[5];
		char sex[3];
		int old;
		char school[100];
		int payment;
		char address[100];
		char tel[12];
	while(fscanf(fp,"%lld%s%s%d%s%d%s%s",&id,name,sex,&old,school,&payment,address,tel) ==8){
		if(n==2)	{
		a[i].id=id;
		strcpy(a[i].name,name);
		strcpy(a[i].sex,sex);
		a[i].old=old;
		strcpy(a[i].school,school);
		a[i].payment=payment;
		strcpy(a[i].address,address);
		strcpy(a[i].tel,tel);
		printf("id%dְ����Ϣ���£�\n\tְ���ţ�%lld\n\t������%s\n\t�Ա�%s\n\t���䣺%d\n\tѧ����%s\n\t���ʣ�%d\n\tסַ��%s\n\t�绰��%s\n",i++,id,name,sex,old,school,payment,address,tel);
		}
		i++;		
	}
	return a;
}
int main(){
	//data* head;
	//head=creat();
	list();
	select(2);
	return 0;
}

