#include<iostream>
using namespace std;
int const N = 1000;

int cn = 0;  //��¼��ǰ����ڵ���
int fn = 0;  //��¼ʣ��ڵ���
int bestx[N]; 
int x[N];
int n, m;
int map[N][N];

//�жϵ�t�������Ƿ���Լ��� 
int check(int t) {
	bool flag = true;
	for (int i = 1; i < t; i++) {
		if (x[i] && map[i][t] == 0) {  //��t��������ǰt-1���ޱ�������ǰt�������ڼ����� 
			flag = false;
			break;
		}
	}
	return flag;
}

void backtrack(int t) {
	//���ﵽҶ�ӽڵ�ʱ
	if (t > n) {
		for (int i = 1;)
	} 
} 



int main () {
	int u, v; 
	cout <<"����ͼ�еĽڵ���n:"<<endl;
	cin >> n;
	cout <<"����ͼ�еı���m:" <<endl;
	cin >> m;
	cout <<"����ͼ�������ߵ���������u��v:" <<endl;
	for (int i = 1; i <= m; i++) {
		cin >> u;
		cin >> v;
		map[u][v] = map[v][u] = 1;
	} 
	//��ʼ��
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 0;
		}
	} 
	backtrack(1);
	return 0;
} 
