#include<stdio.h>
#define MAX 100
int n;  //记录地图中的顶点数
int edge;  //记录地图中的边数
int m;  //记录可绘制的颜色总数 
int map[MAX][MAX] = {0};  //创建图的邻接矩阵
int x[MAX];  //记录可绘制的颜色
int sum = 0; //记录可行方案总数 
//初始化地图的邻接矩阵
void creatMap() {
	int i, j;
	int u, v;
	for (i = 1; i <= edge; i++) {
		scanf("%d %d",&u,&v);
		map[u][v] = map[v][u] = 1;
	}
} 
//判断当前顶点是否可以拓展
int place(int t) {
	int i, j;
	int ok = 1;
	//判断当前顶点是否与已经着色顶点右边相连，是否颜色相同 
	for (i = 1; i < t; i++) {
		if (map[t][i] == 1) {
			if (x[t] == x[i]) {
				ok = 0;
				break;
			}
		}
	}
	return ok;
} 
//搜索函数
void backTrack(int t) {
	int i, j;
	//当前节点为叶子节点，找到一种可行方案，输出
	if (t > n) {
		sum++;
		printf("第%d种方案着色为：\n",sum);
		for (i = 1; i <= n; i++) {
			printf("%d ",x[i]);
		}
		printf("\n");
	} 
	else {
		//每个顶点绘制不同颜色
		for (i = 1; i <= m; i++) {
			x[t] = i;
			//满足条件则搜索 
			if (place(t)) {
				backTrack(t+1);
			}
		} 
	}
} 
int main() {
	int i, j;
	printf("请输入地图中的顶点数n：\n");
	scanf("%d",&n);
	printf("请输入图中的边的总数edge：\n");
	scanf("%d",&edge);
	printf("请输入可绘制的颜色总数m：\n");
	scanf("%d",&m);
	printf("请输入图中相连边的顶点u和v：\n");
	creatMap();
	backTrack(1); 
	return 0;
} 
