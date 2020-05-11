
/**
    dijistra�㷨�����·��˼��
	   1����ʼ��dist[], p[]���������б�������p[]���ǰ����������-1
	   2������С�ټ���V-U������̰�Ĳ����ҵ�ʹ��dist[i]����С�Ķ���t���򶥵�t���Ǽ���v-u�о���Դ��u����Ķ���
	   3����t����s�����У�ͬʱ����v-s
	   4��������v-sΪ�գ���������������5
	   5���Ѿ��ҵ��˵�Դ������Ķ���t��ô��v-s���������е�Ԫ���붥�������ڵĶ���j�����Խ���t�߽ݾ����жϾ����ϵ����dist 

*/




#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 1000;
const int INF = 9999;

int map[MAX][MAX];  //��ʾ��ͼ���ڽӾ���
int dist[MAX];  //��¼Դ�㵽�ڵ�i�����·������
int p[MAX];  //��¼���·���ڵ�i��ǰ��
bool flag[MAX];  //��ʾ�ڵ�i�Ƿ񱻷��� 
int n, m;  //�������Ķ������ͱ��� 

//dijistra�㷨
void dijistra(int u0) {
	for (int i = 1; i <= n; i++) {
		dist[i] = map[u0][i];
		flag[i] = false;
		if (map[u0][i] < INF) {
			p[i] = u0;
		} else {
			p[i] = -1;
		}
	}
	//��־�ڵ�u0�Ѿ������ʹ�
	flag[u0] = true; 
	dist[u0] = 0;
	for (int i = 1; i <= n; i++) {
		int temp = INF;
		int t = u0;
		//��V-U�������ҵ�����u0��������Ķ���
		for (int j = 1; j <= n; j++) {
			if (!flag[j] && temp > dist[j]) {
				t = j;
				temp = dist[j];
			}
		} 
		//�ж��Ƿ��ҵ�
		if (t == u0) {
			return;
		} 
		//�ҵ� 
		flag[t] = true;
		//���½��v-u��t�ڽӶ��㵽Դ��ľ���
		for (int j = 1; j <= n; j++) {
			if (!flag[j] && map[t][j] < INF) {  //���ڽӵ� 
				if (dist[j] > map[t][j] + dist[t]) {
					dist[j] = map[t][j] + dist[t];
					p[j] = t;
				}
			}
		} 
	}
} 

int main () {
	int u, v, u0, w;
	//�������Ķ������ͱ���
	cin >> n >> m;
	//��ʼ������
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	} 
	//���붥���Լ�������֮��Ȩֵ
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		map[u][v] = w;
	} 
	//����Զ��
	cin >> u0; 
	dijistra(u0);
	for (int i = 1; i <= n; i++) {
		cout <<"С��Ҫȥ��λ�ã�"<< i ;
		if (dist[i] == INF) {
			cout<<"��·����"<<endl;
		} else {
			cout<<"��̾��룺"<< dist[i]<<endl;
		} 
	}
	return 0;
}
