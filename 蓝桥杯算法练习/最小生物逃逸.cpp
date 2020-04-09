#include<stdio.h>
#define MAX 101
int main () {
	int n, m;
	int i, j, count, f, sum;
	int a[MAX][4], b[MAX][3];  //数组a中每行存储着星球的坐标和半径，数组b中存储着生物的坐标
	//输入星球数和生物数
	scanf("%d %d", &n, &m);
	//分别输入星球坐标半径和生物坐标
	for (i = 0; i < n+m; i++) {
		//先输入星球的坐标
		if (i < n) {
			for (j = 0; j < 4; j++) {
				scanf("%d", &a[i][j]);
			}
		} else {
			for (j = 0; j < 3; j++) {
				scanf("%d", &b[i-n][j]);
			}
		}
	} 
	//求结果
	for (i = 0; i < m; i++) {
		//逃逸层数清零 
		count = 0;
		for (j = 0; j < n; j++) {
			sum  = 0;  //用来俩个点距离的平方
			f = 2;
			do{
				sum += (a[j][f]-b[i][f])*(a[j][f]-b[i][f]);
			} while (f--);
			//判断此距离和半径的值的平方
			if (sum < a[j][3]*a[j][3]) {
				count++;
			} 
		}
		printf("%d ", count);
	} 
	return 0;
}
