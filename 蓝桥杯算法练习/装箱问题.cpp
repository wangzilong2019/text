#include<stdio.h>
//求俩个数的最大值
int max(int a, int b) {
	return a>b ? a:b;
} 

int main () {
	int V, n;
	int maxv[31][20001] = {0};  //表示前i和物品装到箱子体积为j中所得的最大价值 
	int i, j, t;
	//输入箱子总体积和装入箱子物品个数
	scanf("%d %d", &V, &n);

	for (i = 1; i <= n; i++) {
		//输入每个箱子的体积
		scanf("%d", &t);
		//判断是否能装入箱子
		for (j = 1; j <= V; j++) {
			//不能装入箱子
			if (t > j) {
				maxv[i][j] = maxv[i-1][j];
			} 
			//装物品判断那个体积更大
			else {
				maxv[i][j] = max(maxv[i-1][j], maxv[i-1][j-t]+t);
			} 
		} 
	}
	//输出最小剩余体积
	printf("%d",V-maxv[n][V]); 
	return 0;
}
