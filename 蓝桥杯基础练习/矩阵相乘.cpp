#include<stdio.h>
#define MAX 31
int main () {
	int c[MAX][MAX] = {0};
	int a[MAX][MAX], b[MAX][MAX], d[MAX][MAX];
	int i, j, k, m, n;
	//输入矩阵的阶数和幂数
	scanf("%d %d",&n ,&m);
	//输入矩阵的元素
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d",&a[i][j]);
			b[i][j] = a[i][j]; 
			if (i == j) {
				d[i][j] = 1;
			}
			else {
				d[i][j] = 0;
			}
		}
	} 
	//如果m的值为0
	if (m == 0) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%d ",d[i][j]);
			}
			printf("\n");
		} 
		return 0;
	}
	//计算矩阵相乘结果
	for (m = m-1; m > 0; m--) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
					c[i][j] += b[i][k] * a[k][j];
				}
			}
		}
		//将数组c的每个元素值赋给数组b，且将数组每个元素赋值0 
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				b[i][j] = c[i][j];
				c[i][j] = 0;
			}
		}
	} 
	//输出结果
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ",b[i][j]);
		}
		printf("\n");
	} 
	return 0;
} 
