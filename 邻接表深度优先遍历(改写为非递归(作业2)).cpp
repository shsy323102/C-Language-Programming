//�㷨6.6�������ڽӱ��ʾͼ�����������������
#include <iostream>
using namespace  std;

#define MVNum 100							//��󶥵���
typedef char VerTexType;					//���趥�����������Ϊ�ַ��� 


//-------------ͼ���ڽӱ�---------------------
typedef struct ArcNode{                		//�߽�� 
    int adjvex;                          	//�ñ���ָ��Ķ����λ�� 
    struct ArcNode *nextarc;          		//ָ����һ���ߵ�ָ�� 
}ArcNode; 

typedef struct VNode{ 
    VerTexType data;                    	//������Ϣ
    ArcNode *firstarc;                		//ָ���һ�������ö���ıߵ�ָ�� 
}VNode, AdjList[MVNum];               		//AdjList��ʾ�ڽӱ����� 
typedef struct{
    AdjList vertices;                 		//�ڽӱ� 
    int vexnum, arcnum;              		//ͼ�ĵ�ǰ�������ͱ��� 
}ALGraph;

typedef struct SNode{
	int data;
	struct SNode *next;
}SNode,*LinkStack;

bool visited[MVNum];           				//���ʱ�־���飬���ֵΪ"false" 

int InitStack(LinkStack &S)
{
	S = NULL;
	return 1;
}
bool StackEmpty(LinkStack S)
{
	if(!S)
		return true;
	return false;
}
int Push(LinkStack &S,int e)
{
	SNode *p = new SNode;
	if(!p)
	{
		return -1;
	}
	p->data=e;
	p->next = S;
	S = p;
	return 1;
}
int Pop(LinkStack &S,int &e)
{
	SNode *p;
	if(!S)
		return 0;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return 1;
}
int getTop(LinkStack &S) //�õ�ջ��Ԫ��  
{  
    return S->data;  
}  
int LocateVex(ALGraph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
		return -1;
}//LocateVex

void CreateUDG(ALGraph &G){ 
	//�����ڽӱ��ʾ������������ͼG
	int i , k;
	
	cout <<"�������ܶ��������ܱ������Կո����:";
	cin >> G.vexnum >> G.arcnum;				//�����ܶ��������ܱ��� 
    cout << endl;
	
	cout << "���������ƣ���a" << endl;

	for(i = 0; i < G.vexnum; ++i){          	//������㣬�����ͷ����
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vertices[i].data;           	//���붥��ֵ 
		G.vertices[i].firstarc=NULL;			//��ʼ����ͷ����ָ����ΪNULL 
    }//for
	cout << endl;
    
	cout << "����������Ķ��㣬��a b" << endl;

	for(k = 0; k < G.arcnum;++k){        		//������ߣ������ڽӱ�
		VerTexType v1 , v2;
		int i , j;
		cout << "�������" << (k + 1) << "���������Ķ���:";
		cin >> v1 >> v2;                 		//����һ������������������
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		//ȷ��v1��v2��G��λ�ã���������G.vertices�е���� 
		
		ArcNode *p1=new ArcNode;               	//����һ���µı߽��*p1 
		p1->adjvex=j;                   		//�ڽӵ����Ϊj 
		p1->nextarc= G.vertices[i].firstarc;  G.vertices[i].firstarc=p1;  
		//���½��*p1���붥��vi�ı߱�ͷ��
		
		ArcNode *p2=new ArcNode;                //������һ���ԳƵ��µı߽��*p2 
		p2->adjvex=i;                   		//�ڽӵ����Ϊi 
		p2->nextarc= G.vertices[j].firstarc;  G.vertices[j].firstarc=p2;  
		//���½��*p2���붥��vj�ı߱�ͷ�� 
    }//for 
}//CreateUDG

void DFS(ALGraph G, int v){        				//ͼGΪ�ڽӱ����� 
	cout << G.vertices[v].data << "   ";  
	visited[v] = true;    						//���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue 
	ArcNode *p = G.vertices[v].firstarc;		//pָ��v�ı�����ĵ�һ���߽�� 
	while(p != NULL){              				//�߽��ǿ� 
		int w = p->adjvex;               		//��ʾw��v���ڽӵ� 
		if(!visited[w])  DFS(G, w);   			//���wδ���ʣ���ݹ����DFS 
		p = p->nextarc;                			//pָ����һ���߽�� 
	} 
}//DFS

void fun(ALGraph G, int v){  
	int w,i;
	ArcNode *p;
	LinkStack S;  
	InitStack(S);
	Push(S,v);				       					 	       				
	while(!StackEmpty(S)){
			w =getTop(S);
				if(!visited[w]){
				cout << G.vertices[w].data << "   ";  
				visited[w] = true;  
				}
				p=G.vertices[w].firstarc;
				while(p){
					i=p->adjvex;
					if(!visited[i]){
						cout << G.vertices[i].data << "   ";
						visited[i] = true;
						Push(S,i);
						p=G.vertices[i].firstarc;
					}else {
						p=p->nextarc;
					}
				}
			Pop(S,w);
		}
}//DFS
int main(){
	cout << "************�㷨6.6�������ڽӱ��ʾͼ�����������������**************" << endl << endl;
	ALGraph G;
	CreateUDG(G);
	cout << endl;
	cout << "������ͨͼG������ɣ�" << endl << endl;

	cout << "�����������ͨͼ����ʼ�㣺";
	VerTexType c;
	cin >> c;
	
	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(c == G.vertices[i].data)
			break;
	}
	cout << endl;
	while(i >= G.vexnum){
		cout << "�õ㲻���ڣ����������룡" << endl;
		cout << "�����������ͨͼ����ʼ�㣺";
		cin >> c;
		for(i = 0 ; i < G.vexnum ; ++i){
			if(c == G.vertices[i].data)
				break;
		}
	}

//	cout << "���������������ͼ�����" << endl;
//	DFS(G , i);
//	cout <<endl;
	
	cout << "���������������ͼ���(�ǵݹ�)��" << endl;
	fun(G , i);
	cout <<endl;
	return 0;
}//main
