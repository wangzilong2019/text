
/**
    ���鼯
	���鼯��һ�����ݽṹ������������һЩ���ཻ�ļ���
	   1����ʼ��ÿ���������ڵļ���Ϊ���� 
	   2�������������Ϻ��Ǽ�Ϊ�������ڼ��Ϻţ����õݹ�ķ������ң����ڼ��Ϻŵ����Լ�ʱ��ֹͣ
	      �ڻع�ʱ���ѵ�ǰ�ڵ㵽����·���ϵ����нڵ�ͳһ��Ϊ���ڵļ��Ϻ�
	   3���ϲ�������Ԫ�ؼ��ϺŲ�ͬʱ���ϲ���һ������ 
    
*/

#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
const int N = 100;
int n, m;  //����ڵ����ͱ��� 
int father[N];

struct Edge{
	int u, v;  //ÿ���ߵ��������� 
	int w;  //�ߵ�Ȩֵ 
}e[N*N];

//��ʼ��
void init(int n) {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
} 

//�����������ȼ�
bool comp(Edge x, Edge y) {
	return x.w < y.w;
} 

//���鼯ʱ������
int find(int x) {
	//��ǰ���ϺŲ��������ڼ��Ϻ�ʱ�ݹ�������
	if (x != father[x]) {
		father[x] = find(father[x]);  //�ѵ�ǰ�ڵ㵽����·�������м��ϺŸ�Ϊ���� 
	} 
	return father[x]; //�������ڽڵ�ļ��Ϻ� 
} 

//�ϲ����ϲ���
int merge(int a, int b) {
	//�ֱ�������ߵļ��Ϻ�
	int p = find(a);
	int q = find(b); 
	if (p == q) {
		return 0;
	}
	//��С�ļ��ϺŸ�����ļ��Ϻ�
	if (p < q) {
		father[q] = p;
	} else {
		father[p] = q;
	}
} 

//Kursal�㷨
int kurskal() {
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		//���Ժϲ�
		if (merge(e[i].u, e[i].v)) {
			ans += e[i].w;
			n--;
			//���ϲ�n-1����ʱ����
			if (n == 1) {
				return ans;
			} 
		} 
	}
	return 0;
} 

int main () {
	cout <<"����ͼ�еĽڵ���n�ͱ���m��"<<endl;
	cin >> n >> m;
	cout <<"����ÿ���ߵ���������u��v��Ȩֵw��"<<endl;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	//��ʼ��
	init(n);
	//��������
	sort(e, e + m, comp);
	//kurskal�㷨
	int ans = kurskal(); 
	cout<<"��С��������ȨֵΪ��" << ans <<endl;
	return 0;
}
