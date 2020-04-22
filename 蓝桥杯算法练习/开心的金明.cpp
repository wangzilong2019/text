#include<stdio.h>
#define max(a, b) a>b ? a:b
#include<stdlib.h>
#define N 1001
#define M 30
#define MAX 1001
int main () {
	int m, n;
	int i, j;
	int p[MAX], v[MAX];
	int c[N][M] = {0};
	//输入总钱数m和物品个数n
	scanf("%d %d", &m, &n); 
	//动态申请空间，创建数组存放每个物品的价格个满意度
	//输入米格物品的价格和满意度
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &v[i], &p[i]);
	} 
	//计算
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			//判断物品是否可以买
			if (v[i] > j) {
				c[i][j] = c[i-1][j];
			} else {
				c[i][j] = max(c[i-1][j-v[i]] + v[i]*p[i], c[i-1][j]);
			}
		}
	} 
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	printf("%d", c[n][m]);
	return 0;
}
