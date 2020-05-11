
/**
    dijistra算法求最短路径思想
	   1、初始化dist[], p[]若俩个点有边相连，p[]存放前驱，否则存放-1
	   2、找最小再集合V-U中依照贪心策略找到使得dist[i]有最小的顶点t，则顶点t就是集合v-u中距离源点u最近的顶点
	   3、将t加入s集合中，同时更新v-s
	   4、若集合v-s为空，则结束，否则继续5
	   5、已经找到了到源点最近的顶点t那么对v-s集合中所有的元素与顶点他相邻的顶点j都可以借助t走捷径，判断距离关系更新dist 

*/




#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 1000;
const int INF = 9999;

int map[MAX][MAX];  //表示的图的邻接矩阵
int dist[MAX];  //记录源点到节点i的最短路径长度
int p[MAX];  //记录最短路径节点i的前驱
bool flag[MAX];  //表示节点i是否被访问 
int n, m;  //输入矩阵的定点数和边数 

//dijistra算法
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
	//标志节点u0已经被访问过
	flag[u0] = true; 
	dist[u0] = 0;
	for (int i = 1; i <= n; i++) {
		int temp = INF;
		int t = u0;
		//从V-U集合中找到距离u0距离最近的顶点
		for (int j = 1; j <= n; j++) {
			if (!flag[j] && temp > dist[j]) {
				t = j;
				temp = dist[j];
			}
		} 
		//判断是否找到
		if (t == u0) {
			return;
		} 
		//找到 
		flag[t] = true;
		//更新结合v-u与t邻接顶点到源点的距离
		for (int j = 1; j <= n; j++) {
			if (!flag[j] && map[t][j] < INF) {  //右邻接点 
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
	//输入矩阵的顶点数和边数
	cin >> n >> m;
	//初始化矩阵
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	} 
	//输入顶点以及俩个点之间权值
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		map[u][v] = w;
	} 
	//输入远点
	cin >> u0; 
	dijistra(u0);
	for (int i = 1; i <= n; i++) {
		cout <<"小明要去的位置："<< i ;
		if (dist[i] == INF) {
			cout<<"无路可走"<<endl;
		} else {
			cout<<"最短距离："<< dist[i]<<endl;
		} 
	}
	return 0;
}
