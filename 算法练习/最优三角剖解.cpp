#include<stdio.h>
#define MAX 100
int s[MAX][MAX]={0};  //记录最优剖解位置
double m[MAX][MAX]={0},g[MAX][MAX];  //m[][]记录最优权值，g[][]记录整个权值
int n;  //记录图中顶点个数
void f() {
	int d,i,j,k;
	for (d = 2; d <= n; d++) {
		for (i = 1; i <= n-d+1; i++) {
			j = i-d+1;
			m[i][j] = m[i+1][j] + g[i-1][i] + g[i][j] + g[i-1][j];
			s[i][j] = i;
			for (k = i+1; k < j; k++) {
				double temp = m[i][k] + m[k][j] + g[i-1][k] + g[k][j] + g[i-1][j];
				if (m[i][j] > temp) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
			
		}
	}
} 
//输出最优路径
void print(int i, int j) {
	if (i == j) {
		return ;
	}
	if (s[i][j] > i) {
		printf("{v%dv%d}",i-1,s[i][j]);
	}
	if (j > s[i][j] + 1) {
		printf("{v%dv%d}",s[i][j],j);
	}
	print(i,s[i][j]);
	print(s[i][j]+1,j);
} 
int main() {
	int i, j;
	printf("请输入顶点个数：\n");
	scanf("%d",&n);
	printf("请以此输入连接各顶点的权值：\n");
	for (i = 0; i <= n; i++) {
		for (j = 0; j <=n; j++) {
			scanf("%lf",&g[i][j]);
		}
	}
	printf("输出权值的最优值：\n");
	f();
	printf("%lf\n",m[1][n]);
	print(1,n);
	return 0;
} 
