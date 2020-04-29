#include<iostream>
#include<queue>
#include<iomanip> 
#include<cstring>
using namespace std;
const int MAXN = 1001; //���ڵ���
const int INF = (1<<30) - 1;
int g[MAXN][MAXN];  //������������ʼʱ����Ϊ����
int f[MAXN][MAXN];  // ʵ����������ʼʱ����Ϊ0
int pre[MAXN];  //��¼ǰ������
bool vis[MAXN];
int n, m;

//����е�����ҿ�����·��
bool bfs(int s, int t) {
	int i;
	//��ʼ��ǰ�������Լ���¼����
	memset(pre, -1, sizeof(pre));
	memset(vis, false, sizeof(vis));
	//����һ������ 
	queue<int>q;
	//��Դ���ʼ��
	vis[s] = true;
	q.push(s);
	while (!q.empty()) {
		//��¼��ǰ��ͷԪ��
		int now = q.front();
		q.pop();
		//Ѱ�ҿ�����·��
		for (i = 1; i <= n; i++) {
			//��δ���������б����� 
			if(!vis[i] && g[now][i] > 0) {
				vis[i] = true;
				pre[i] = now;
				//�ж��Ƿ��ҵ�������·��
				if (i == t) {
					return true;
				} 
				q.push(i);
			}
		} 
	} 
	return false;  //�Ҳ���������·�� 	 
}

int EK(int s, int t) {
	int d, v, w, maxflow;
	maxflow = 0;
	while (bfs(s, t)) {  //����������ʱ 
		v = t;
		d = INF;
		while (v != s) {  //�ҵ�������d 
			w = pre[v];
			if (d > g[w][v]) {
				d = g[w][v];
			}
			v = w;
		}
		maxflow += d;
		v = t;
		while (v != s) {  //�ؿ�����·������ 
			w = pre[v];
			g[w][v] -= d; //��������������߼���
			g[v][w] += d; //�������������������
			//ʵ�����������Ƿ���������
			if (f[v][w] > 0) {
				f[v][w] -= d;
			} else {
				f[w][v] += d;
			}
			v = w;
		}
	}
	return maxflow;
} 


int main () {
	int u, v, w;
	int i;
	//��ʼ��ʵ��������ÿ���ߵ�Ȩֵ
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g)); 
	//cout<<"������ڵ����n�ͱߵ�����m"<<endl;
	cin>>n>>m;
	//cout<<"�������������Լ��ߵ�����"<<endl;
	for (i = 0; i < m; i++) {
		cin>>u>>v>>w;
		g[u][v] += w;
	}
	cout<<EK(1, n)<<endl;
	return 0;
} 
