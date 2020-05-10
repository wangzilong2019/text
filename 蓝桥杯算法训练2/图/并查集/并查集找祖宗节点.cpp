#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100001;
int father[N];
int n, m;  //�ֱ��¼����ͱߵĸ���
struct Edge{
	int u, v; //ÿ���ߵ��������� 
}e[N]; 

//��ʼ��ÿ��������ĸ��ڵ� 
void init() {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
} 

//������
int find(int x) {
	if (x != father[x]) {
		father[x] = find(father[x]);  //�ѵ�ǰ�ڵ㵽�����ڽڵ�ļ��Ϻ�ȫ����Ϊ���ڽڵ㼯�Ϻ� 
	}
	return father[x];  //�������ڼ��Ϻ� 
} 

int main () {
	int count = 0;
	//���붥��ͱߵĸ���
	cin >>n >>m;
	//����ÿ���ߵ���������
	for (int i = 1; i <= m; i++) {
		cin>> e[i].u>> e[i].v;
	} 
	init();
	//����
	for (int i = 1; i <= m; i++) {
		//�ҵ���ǰ��������ļ��Ϻ�
		int p = find(e[i].u);
		int q = find(e[i].v);
		//����������ļ��Ϻ���ͬ���ۼ�����1
		if (p == q) {
			count++;
		} else if (p > q) {
			father[p] = q;
		} else {
			father[q] = p;
		}
	} 
	//���ò��鼯˼�룬�����������ڽڵ㼴1�Žڵ���ͬ��ֵ��������1 
	for (int i = 1; i <= n; i++) {
		if (father[i] == 1) {
			count++;
		}
	}
	//��������
	cout<<count<<endl; 
	return 0;
} 
