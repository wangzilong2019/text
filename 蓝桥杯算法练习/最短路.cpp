#include<stdio.h>
#define MAX 20001
#define INF 88888
int map[MAX][MAX] = {INF};
int d[MAX];
int p[MAX];
int flag[MAX];
int n;
void dijistra(int u) {
	//初始化矩阵以及数组
	int i, j;
	int temp, t;
	for (i = i; i <= n; i++) {
		d[i] = map[u][i];
		flag[i] = 0;
		if (d[i] == INF) {
			p[i] = -1;
		}
		else {
			p[i] = u;
		}
	} 
	//将第一个节点加入其中 
	flag[u] = 1;
	d[u] = 0;
	//依次找到最短路径
	for (i = 1; i <= n; i++) {
		temp = INF;
		t = u;
		//找到最短路径的俩个点
		for (j = 1; j <= n; j++) {
			if (!flag[j] && d[j] < temp) {
				t = j;
				temp = d[j];
			}
		} 
		//找不到t退出 
		if (u == t) {
			return ;
		} 
		//找到将t节点加入
		flag[t] = 1;
		//更新解集合v-s中与t邻接点到源点u的距离
		for (j = 1; j <= n; j++) {
			if (!flag[j] && map[t][j] < INF) {
				if (d[j] > d[t]+map[t][j]) {
					d[j] = d[t]+map[t][j];
					p[j] = t;
				}
			}
		} 
	} 
	
}
int main () {
	int m;
	int i, j;
	int u, v, w;
	//输入图中的定点数
	scanf("%d", &n);
	//输入图中的边数
	scanf("%d", &m);
	//输入图中的定点以及对应的权值
	while (m--) {
		scanf("%d %d %d",&u, &v, &w);
		map[u][v] = w;
	} 
	dijistra(0);
	for (i = 2; i <= n; i++) {
		printf("%d\n",d[i]);
	}
	return 0;
}
