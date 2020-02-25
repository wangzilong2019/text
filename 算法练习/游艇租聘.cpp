#include<stdio.h>
#include<string.h>
#define MAX 100
int r[MAX][MAX],m[MAX][MAX];  //记录i到j站的租金
int s[MAX][MAX];  //记录i到j站之间的停靠站台
int n;  //输入站台数 
void rent() {
	int d,k,i,j;
	//计算经过三个顶点至n个顶点的最优路径
	 
	for (d = 3; d <=n; d++) {
		for (i = 1; i <= n-d+1; i++) {
			j = i+d-1;
			for (k = i+1; k < j; k++) {
				int temp = m[i][k] + m[k][j];
				if (temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
}
//记录最短路径
void print(int i, int j) {
	if (s[i][j] == 0) {
		printf("%d-",j);
		return ;
	}
	print(i, s[i][j]);
	print(s[i][j],j);
} 
int main() {
	int i,j;
	printf("请输入游艇停靠的站台数n：\n");
	scanf("%d",&n);
	printf("请输入各站台之间的费用：\n");
	for (i = 1; i <= n; i++) {
		for (j = i+1; j <= n; j++) {
			scanf("%d", &r[i][j]);
			m[i][j] = r[i][j];
		}
	}
	//计算最优费用
	rent();
	printf("最优花费：\n");
	printf("%d\n",m[1][n]);
	printf("输入最优路径：\n");
	printf("1-"); 
	print(1, n); 
	return 0;
}  
