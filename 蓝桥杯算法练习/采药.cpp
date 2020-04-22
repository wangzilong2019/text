#include<stdio.h>
#define max(a, b) a>b ? a:b
#define MAX 1000 
int v[MAX], t[MAX];
int main () {
	int i, j, T, M;
	int c[MAX][MAX] = {0};
	//输入采药总时间和山洞里药材数目
	scanf("%d %d", &T, &M);
	//输入每个药材的采摘时间和价值
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t[i], &v[i]);
	} 
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= T; j++) {
			//判断第i个药材是否可以采摘
			if (t[i] <= j) {
				c[i][j] = max(c[i-1][j], c[i-1][j-t[i]] + v[i]);
			} else {
				c[i][j] = c[i-1][j];
			}
		}
	}
	printf("%d", c[M][T]);
	return 0;
}
