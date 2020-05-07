/**
   最小生成树的算法（Kruskal）
      1、初始化，将图G的边集合E所有边的权值从小到大排序，把每个顶点都孤立为一个连通分支，每个顶点对应一个集合
	  2、在集合E中找到权值最小的边（i，j）
	  3、如果顶点i和j位于俩个不同的连通分支，则将边（i，j）加入集合E，执行合并操作
	  4、将边（i，j）从E中删除
	  5、若选取的变得个数小于n-1转步骤2，否则结束算法生成最小生成树 

*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100;
int node[N];  //存放节点编号
int n, m;

struct Edge {
	int u;
	int v;
	int w;
}e[N*N];

//定义排序优先级
bool comp (Edge x, Edge y) {
	return x.w < y.w;
} 

//初始化
void init(int n) {
	for (int i = 1; i <= n; i++) {
		node[i] = i;
	}
} 

//合并边操作
int merge(int a, int b) {
	int p = node[a];
	int q = node[b];
	//若俩个节点在同一个集合则不能合并退出
	if (p == q) {
		return 0;
	} 
	//检查把所有集合集为q的改成p
	for (int i = 1; i <= n; i++) {
		if (node[i] == q) {
			node[i] = p;
		}
	} 
	return 1;
} 

//最小生成树算法
int kruskal (int n) {
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		//若可以合并
		if (merge(e[i].u, e[i].v)) {
			ans += e[i].w;
			n--;
			//若生成一颗最小生成树则退出
			if (n == 1) {
				return ans;
			} 
		} 
	}
	return 0;
} 

int main () {
	cout << "输入节点数n和边数m" <<endl;
	cin >> n >> m;
	cout << "输入节点u和v以及权值w" << endl;
	for (int i = 1;i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	//初始化
	init(n);
	//排序
	sort(e, e + m, comp); 
	int ans = kruskal(n);
	cout <<"最小花费是：" << ans <<endl; 
	return 0;
}
