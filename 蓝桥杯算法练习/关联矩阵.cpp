#include<stdio.h>
#define N 101
int main () {
	int a[N][N] = {0};
	int n, m;
	int i, j;
	int step;
	//���붨�����ͱ���
	scanf("%d %d", &n, &m);
	//����ÿ���ߵĶ���
	for (step = 1; step <= m; step++) {
		scanf("%d %d", &i, &j);
		a[i][step] = 1;
		a[j][step] = -1;
	}
	//�����������
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
