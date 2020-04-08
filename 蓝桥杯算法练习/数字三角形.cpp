#include<stdio.h>
#define MAX 101
//求俩个数的最大值
int maxv(int a, int b) {
	return a>b ? a:b;
} 

int main () {
	int a[MAX][MAX] = {0};
	int n, i, j, max;
	//输入三角矩阵的行数
	scanf("%d", &n);
	//读入矩阵
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	} 
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			a[i][j] = maxv(a[i-1][j-1], a[i-1][j]) + a[i][j];
		}
	} 
	max = a[n][1];
	//找到最大值
	for (j = 2; j <= n; j++) {
		if (a[n][j] > max) {
			max = a[n][j];
		}
	} 
	printf("%d", max);
	return 0;
}
