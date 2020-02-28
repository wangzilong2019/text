#include<stdio.h>
#define MAX 100
int n;  //图中的顶点数
int m;  //图中有顶点相连接的边数
int x[MAX];  //记录每次顶点
int bestx[MAX];  //记录顶点最优值
int a[MAX][MAX] = {0};  //记录图中相连顶点边
int cn = 0;  //记录当前加入图中的顶点总数
int bestn;  //记录最优顶点总数
//判断第t个顶点是否可以加入图中
int place(int t) {
	int ok = 1;
	for (int i = 1; i < t; i++) {
		//判断是否有边相连 
		if (x[i] && a[t][i] == 0) {
			ok = 0;
			break;
		}
	}
	return ok;
} 
//拓展节点
void backTrack(int t) {
	int i, j;
	//当前节点为叶子节点，则找到一次最优值记录
	if (t > n) {
		for (i = 1; i <= n; i++) {
			bestx[i] = x[i];
		}
		//记录最大团数量
		bestn = cn;
		return ; 
	} 
	//搜索左子树
	if (place(t)) {
		x[t] = 1;
		cn++;
		backTrack(t+1);
		cn--;
	} 
	//搜索右子树
	if (cn + n -t > bestn) {
		x[t] = 0;
		backTrack(t+1);
	} 
} 
int main() {
	int u, v, i;
	printf("请输入部落的人数n（顶点数）：\n");
	scanf("%d",&n);
	printf("请输入人与人之间的友好关系m（边数）：\n");
	scanf("%d",&m);
	printf("请以此输入友好关系的俩个人（有边相连的俩个顶点u和v）：\n");
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &u, &v);
		a[u][v] = a[v][u] = 1;
	} 
	backTrack(1);
	printf("部落中的最大团人数为：\n");
	printf("%d\n",bestn);
	printf("部落中的最大团人分别为：\n");
	for (i = 1; i <= n; i++) {
		if (bestx[i] == 1) {
			printf("%d ",i);
		}
	}
	return 0;
}  
