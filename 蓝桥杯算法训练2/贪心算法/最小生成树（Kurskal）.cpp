/**
   ��С���������㷨��Kruskal��
      1����ʼ������ͼG�ı߼���E���бߵ�Ȩֵ��С�������򣬰�ÿ�����㶼����Ϊһ����ͨ��֧��ÿ�������Ӧһ������
	  2���ڼ���E���ҵ�Ȩֵ��С�ıߣ�i��j��
	  3���������i��jλ��������ͬ����ͨ��֧���򽫱ߣ�i��j�����뼯��E��ִ�кϲ�����
	  4�����ߣ�i��j����E��ɾ��
	  5����ѡȡ�ı�ø���С��n-1ת����2����������㷨������С������ 

*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100;
int node[N];  //��Žڵ���
int n, m;

struct Edge {
	int u;
	int v;
	int w;
}e[N*N];

//�����������ȼ�
bool comp (Edge x, Edge y) {
	return x.w < y.w;
} 

//��ʼ��
void init(int n) {
	for (int i = 1; i <= n; i++) {
		node[i] = i;
	}
} 

//�ϲ��߲���
int merge(int a, int b) {
	int p = node[a];
	int q = node[b];
	//�������ڵ���ͬһ���������ܺϲ��˳�
	if (p == q) {
		return 0;
	} 
	//�������м��ϼ�Ϊq�ĸĳ�p
	for (int i = 1; i <= n; i++) {
		if (node[i] == q) {
			node[i] = p;
		}
	} 
	return 1;
} 

//��С�������㷨
int kruskal (int n) {
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		//�����Ժϲ�
		if (merge(e[i].u, e[i].v)) {
			ans += e[i].w;
			n--;
			//������һ����С���������˳�
			if (n == 1) {
				return ans;
			} 
		} 
	}
	return 0;
} 

int main () {
	cout << "����ڵ���n�ͱ���m" <<endl;
	cin >> n >> m;
	cout << "����ڵ�u��v�Լ�Ȩֵw" << endl;
	for (int i = 1;i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	//��ʼ��
	init(n);
	//����
	sort(e, e + m, comp); 
	int ans = kruskal(n);
	cout <<"��С�����ǣ�" << ans <<endl; 
	return 0;
}
