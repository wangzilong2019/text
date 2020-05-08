#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
const int N = 100100;
using namespace std;


int f[1000][1000];
int head[N];  //head[i]代表以i为起点的边的编号
int cnt; 

struct Edge{
	int u,v; //边的起点和终点
	int next;   //指向上一条边的编号 
}e[N];

//向所要链接的表中加入边 
void add(int u, int v) {
	e[cnt].u = u;
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt++;
} 

void dfs(int u, int pre) {  //pre父节点，u起始节点 
	for (int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if (pre == v) {  //若父节点与终点重合（即为叶节点）则不需要dp 
			continue;
		}
		dfs(v, u);  //以起点为父节点继续dp
		f[u][1] += f[v][0];
		f[u][0] += max(f[v][1], f[v][0]); 
	}
}

int main () {
	int n;
	//输入节点个数
	cin>> n;
	//初始化数组
	memset(head, -1, sizeof(head));
	memset(f, 0, sizeof(f));
	//输入每个节点的权值
	for (int i = 1; i <= n; i++) {
		cin >> f[i][1];
	} 
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >>a >>b;
		add(a, b);
		add(b, a);
	}
	//从第一个节点开始
	dfs(1, -1);
	cout<< max(f[1][1], f[1][0]) << endl; 
	return 0;
}
