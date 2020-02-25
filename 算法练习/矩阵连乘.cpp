#include<stdio.h>
#define MAX 100
#include<string.h>
int m[MAX][MAX]={0};  //记录i到j个矩阵少乘法次数 
int s[MAX][MAX]={0};  //记录矩阵相乘位置 
int n;  //记录矩阵的个数
int p[MAX];  //记录矩阵的行数和列数
//求出最优次数
void maxtrichain() {
	int i, j, d, k;
	for (d = 2; d <= n; d++) {
		for (i = 1; i <= n-d+1; i++) {
			j = i+d-1;
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for (k = i+1; k < j; k++) {
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] =k;
				}
			}
		}
	}
} 
//输出最优位置
void print(int i, int j) {
	if (i == j) {
		printf("A[%d]",i);
		return ;
	}
	printf("(");
	print(i, s[i][j]);
	print(s[i][j]+1, j);
	printf(")");
} 
int main() {
	int i, j;
	printf("请输入矩阵的个数n：\n");
	scanf("%d",&n);
	printf("请输入每个矩阵的行数和最后一个矩阵的列数：\n");
	for (i = 0; i <= n; i++) {
		scanf("%d",&p[i]);
	}
	maxtrichain();
	printf("最小计算量的值为：\n");
	printf("%d\n",m[1][n]);
	print(1, n); 
	return 0;
} 
