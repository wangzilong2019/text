
/**
	������j����Ĵ������ڴ��͵�����ĺ������֮�� 
*/ 


#include<stdio.h>
#define MAX 35
int main () {
	int n, m;
	int i, j;
	int dp[MAX][MAX] = {0};  //dp[i][j]��ʾ����i�δ���j�Ĵ��� 
	//����n��m
	scanf("%d %d", &n, &m);
	dp[1][2] = 1;
	dp[1][n] = 1;
	for (i = 2; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (j == 1) {
				dp[i][j] = dp[i-1][2] + dp[i-1][n];
			} else {
				if (j == n) {
					dp[i][j] = dp[i-1][n-1] + dp[i-1][1];
				} else {
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
				}
			}
		}
	} 
	printf("%d", dp[m][1]); 
	return 0;
}
