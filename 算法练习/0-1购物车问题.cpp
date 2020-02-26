#include<stdio.h>
#define MAX 100
int w[MAX];  //记录每个物品的重量
int v[MAX];  //记录每个物品的价值
int n;  //输入物品的数量
int W;  //购物车的载重量
int c[MAX][MAX];  //c[i][j]前j各物品在载重j的购物车中最大价值
int x[MAX];  //记录第i个物品是否放入购物车中 
int max(int a,int b) {
	return a > b ? a : b;
} 
int main() {
	int i, j;
	printf("请输入购物车的载重w：\n");
	scanf("%d",&W);
	printf("请输入物品的个数n：\n");
	scanf("%d",&n);
	printf("请输入每个物品的重量w和价值v：\n");
	for (i = 1; i <= n; i++) {
		scanf("%d %d",&w[i],&v[i]);
	}
	//初始化c[i][j]
	for (i = 0; i <= n; i++) {
		c[i][0] = 0;
	} 
	for (j = 0; j <= W; j++) {
		c[0][j] = 0;
	} 
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= W; j++) {
			//当前物品重量大于购物车重量不放入 
			if (w[i] > j) {
				c[i][j] = c[i-1][j];
			}
			//否则则比较放此物品还是不放此物品价值大 
			else {
				c[i][j] = max(c[i-1][j], c[i-1][j-w[i]] + v[i]);
			}
		}
	}
	printf("放入购物车中的物品的最大价值为：%d\n",c[n][W]);
	//逆向构造最优解
	j = W;
	for (i = n; i >= 1; i--) {
		//判断第i各物品是否装入购物车中 
		if (c[i][j] > c[i-1][j]) {
			j -= w[i];
			x[i] = 1;
		}
		else {
			x[i] = 0;
		}
	} 
	//输出最优解
	for (i = 1; i <= n; i++) {
		if (x[i] == 1) {
			printf("装入购物车的物品为：%d\n",i);
		}
	} 
	return 0;
} 
