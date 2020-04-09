#include<stdio.h>
#include<stdlib.h>
//求范围内权值之和
int sum (int w[], int x, int y) {
	int i;
	int res = 0;
	for (i = x; i <= y; i++) {
		res += w[i];
	}
	return res;
} 

//求范围内格子的最大权值
int max(int w[], int x, int y) {
	int maxv = w[x];
	int i;
	for (i = x+1; i <= y; i++) {
		if (maxv < w[i]) {
			maxv = w[i];
		}
	}
	return maxv;
} 
int main () {
	int n, m;
	int i, j, k;
	int *w, *p, *x, *y, *v;
	//输入n和m
	scanf("%d %d", &n, &m);
	//创建动态数组 
	w = (int *)malloc(sizeof(int)*n);
	p = (int *)malloc(sizeof(int)*m);
	x = (int *)malloc(sizeof(int)*m);
	y = (int *)malloc(sizeof(int)*m);
	v = (int *)malloc(sizeof(int)*m);
	//输入每个格子的权值
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	} 
	//输入操作类型
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &p[i], &x[i], &y[i]);
	} 
	//计算结果
	k = 0;
	for (i = 0; i < m; i++) {
		//判断操作类型
		if (p[i] == 1) {
			w[x[i]-1] = y[i];
		} 
		if (p[i] == 2) {
			v[k++] = sum(w, x[i]-1, y[i]-1);
		}
		if (p[i] == 3) {
			v[k++] = max(w, x[i]-1, y[i]-1);
		}
	}  
	//输入结果
	for (i = 0; i < k; i++) {
		printf("%d\n", v[i]);
	} 
	return 0;
} 
