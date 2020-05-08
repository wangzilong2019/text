#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
const int N = 100100;
using namespace std;


int f[1000][1000];
int head[N];  //head[i]������iΪ���ıߵı��
int cnt; 

struct Edge{
	int u,v; //�ߵ������յ�
	int next;   //ָ����һ���ߵı�� 
}e[N];

//����Ҫ���ӵı��м���� 
void add(int u, int v) {
	e[cnt].u = u;
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt++;
} 

void dfs(int u, int pre) {  //pre���ڵ㣬u��ʼ�ڵ� 
	for (int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if (pre == v) {  //�����ڵ����յ��غϣ���ΪҶ�ڵ㣩����Ҫdp 
			continue;
		}
		dfs(v, u);  //�����Ϊ���ڵ����dp
		f[u][1] += f[v][0];
		f[u][0] += max(f[v][1], f[v][0]); 
	}
}

int main () {
	int n;
	//����ڵ����
	cin>> n;
	//��ʼ������
	memset(head, -1, sizeof(head));
	memset(f, 0, sizeof(f));
	//����ÿ���ڵ��Ȩֵ
	for (int i = 1; i <= n; i++) {
		cin >> f[i][1];
	} 
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >>a >>b;
		add(a, b);
		add(b, a);
	}
	//�ӵ�һ���ڵ㿪ʼ
	dfs(1, -1);
	cout<< max(f[1][1], f[1][0]) << endl; 
	return 0;
}
