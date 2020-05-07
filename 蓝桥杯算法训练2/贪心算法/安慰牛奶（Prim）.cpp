#include<stdio.h>
#define MAX 100001
#define INF 888888
int flag[MAX];  //标记数组用来标记节点i是否加如集合U
int lowCost[MAX];  //表示与i顶点相连的权值最小的边的权值
int closeSet[MAX];  //表示与i相连的权值最小的边的前驱 
void Prim(int n, int u0, int map[MAX][MAX]) {
	int i, j, temp, t;
	//将u0加入集合U中
	flag[u0] = 1;
	//初始化数据 
	for (i = 1; i <= n; i++) {
		if (i != u0) {
			lowCost[i] = map[u0][i];
			closeSet[i] = u0;
			flag[i] = 0;
		} else {
			lowCost[i] = 0;
		}
	}
	
	for (i = 1; i <= n; i++) {
		temp = INF;
		t = u0;
		//从V-U集合中找到与U中相连的最短的点
		for (j = 1; j <= n; j++) {
			if ( (!flag[j]) && (lowCost[j] < temp)) {
				t = j;
				temp = lowCost[j];
			}
		} 
		//若没找到则推出
		if (t == u0) {
			break;
		} 
		//否则加入U中
		flag[t] = 1;
		//更新集合
		for (j = 1; j <= n; j++) {
			if ((!flag[j]) && (lowCost[j] > map[t][j])) {
				lowCost[j] = map[t][j];
				closeSet[j] = t;
			}
		} 
	}
}

int main () {
	int n, p; //记录定点数和边数
	int c[MAX];  //记录每个顶点的权值(安慰时间)
	int map[MAX][MAX];  //记录顶点i和j之间的花费时间
	int u, v, w;
	int minc = INF;

	int sum, temp, t;
	int i, j;
	//输入节点个数和边的个数 
	scanf("%d %d", &n, &p);
	//初始化带权图的矩阵 
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}
	//输入每个节点的权值（安慰每个奶牛的时间）
	for (i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		if (minc > c[i]) {
			minc = c[i];
		}
	} 
	for (i  = 1; i <= p; i++) {
		scanf("%d %d %d", &u, &v, &w);
		map[u][v] = map[v][u] = 2 * w + c[u] + c[v];
	}
	
	Prim(n, 1, map);
	sum = minc;
	//计算最小生成树边的权值之和加最小节点的权值即为安慰牛奶
	for (i = 1; i <= n; i++) {
		sum += lowCost[i];
	} 
	printf("%d", sum);
	return 0;
}
