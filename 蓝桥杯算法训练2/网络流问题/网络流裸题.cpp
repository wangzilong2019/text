#include<iostream>
#include<queue>
#include<iomanip> 
#include<cstring>
using namespace std;
const int MAXN = 1001; //最大节点数
const int INF = (1<<30) - 1;
int g[MAXN][MAXN];  //残余网络流初始时各边为容量
int f[MAXN][MAXN];  // 实际网络流初始时各边为0
int pre[MAXN];  //记录前驱数组
bool vis[MAXN];
int n, m;

//广度有点遍历找可增广路径
bool bfs(int s, int t) {
	int i;
	//初始化前驱数组以及记录数组
	memset(pre, -1, sizeof(pre));
	memset(vis, false, sizeof(vis));
	//建立一个队列 
	queue<int>q;
	//将源点初始化
	vis[s] = true;
	q.push(s);
	while (!q.empty()) {
		//记录当前队头元素
		int now = q.front();
		q.pop();
		//寻找可增广路径
		for (i = 1; i <= n; i++) {
			//当未被访问且有边相连 
			if(!vis[i] && g[now][i] > 0) {
				vis[i] = true;
				pre[i] = now;
				//判断是否找到可增广路径
				if (i == t) {
					return true;
				} 
				q.push(i);
			}
		} 
	} 
	return false;  //找不到可增广路径 	 
}

int EK(int s, int t) {
	int d, v, w, maxflow;
	maxflow = 0;
	while (bfs(s, t)) {  //当可以增广时 
		v = t;
		d = INF;
		while (v != s) {  //找到可增量d 
			w = pre[v];
			if (d > g[w][v]) {
				d = g[w][v];
			}
			v = w;
		}
		maxflow += d;
		v = t;
		while (v != s) {  //沿可增广路径增流 
			w = pre[v];
			g[w][v] -= d; //残余网络中正向边减流
			g[v][w] += d; //参与网络中逆向边增流
			//实际网络中若是反向边则减流
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
	//初始化实际网络流每条边的权值
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g)); 
	//cout<<"请输入节点个数n和边的条数m"<<endl;
	cin>>n>>m;
	//cout<<"请输俩个顶点以及边的容量"<<endl;
	for (i = 0; i < m; i++) {
		cin>>u>>v>>w;
		g[u][v] += w;
	}
	cout<<EK(1, n)<<endl;
	return 0;
} 
