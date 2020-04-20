#include<stdio.h>
#define MAX 101
int dp[MAX][MAX] = {0};
int fx[8] = {2, 1, -1, -2, -2, -1, 1, 2}; //记录方向
int fy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;//格子的行数和列数 
//判断是否出界，是否可以行走
int check(int x, int y) {
	int flag = 1;
	//判断是否出界
	if (x < 0 || y < 0 || x > n-1 || y > m - 1) {
		flag = 0;
	} else {
		//不出界时判断此路径是否可以走
		if (dp[x][y] != 0) {
			flag = 0;
		} 
	}
	return flag;
} 

//打印路径
void print() {
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
} 

//回溯算法
void backtrack (int x, int y, int dep) {
	int i;
	int xx, yy;//记录走之后的方向坐标 
	//分别向八个方向走
	for (i = 0; i < 8; i++) {
		xx = x + fx[i];
		yy = y + fy[i];
		//当此方向未走过(是否出界，是否可以行走)
		if (check(xx, yy)) {
			dp[xx][yy] = dep;
			//判断是否到达终点
			if (dep == n*m) {
				print();
			} else {
				backtrack(xx, yy, dep + 1);
			}
			dp[xx][yy] = 0;//回溯 
		} 
	} 
} 
 
int main () {
	//输入棋盘行数和列数
	scanf("%d %d", &n, &m); 
	dp[0][0] = 1;
	backtrack(0, 0, 2);
	return 0;
}
