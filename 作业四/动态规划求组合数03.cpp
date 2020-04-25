/************begin************/
#include <stdio.h>
#define MAX 100
int cmn(int n,int m)
{
	int i, j;
	int c[MAX][MAX];
	if (m == 0 || n == m) {
		return 1;
	} else {
		for (i = 1; i <= n; i++) {
			c[i][0] = c[i][i] = 1;
		}
		for (i = 2; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				c[i][j] = c[i-1][j] + c[i-1][j-1];
			}
		}
		return c[n][m];
	}
}
void main()
{
	int n,m;   
	printf("请输入n和m(n>m)：");
	scanf("%d,%d",&n,&m); //接收键入的数值
	printf("%d", cmn(n, m));
}
/************end************/


