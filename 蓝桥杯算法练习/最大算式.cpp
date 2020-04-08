#include<stdio.h>
#define MAX 100
long long max(long long a, long long b) {
	return a>b ? a:b;
}
int main () {
	int i, j, p;
	int sum[MAX];
	int n, k;
	int a[MAX];
	int temp = 0;
	long long dp[MAX][MAX] = {0};  //dp[i][j]代表前i个数字有j个乘号最大乘积 
	//输入数字的个数和划分次数 
	scanf("%d %d", &n, &k);
	//输入每个数字
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		temp += a[i];
		sum[i] = temp;
	} 
	for (i = 1; i <= n; i++) {
		dp[i][0] = sum[i];
	}
	//外层循环代表乘号的个数
	for (j = 1; j <= k; j++) {
		//此层循环代表数字个数
		for (i = 1; i <= n; i++) {
			//乘号的个数小于数字的个数
			if (j < i) {
				//此层循环代表乘号的位置
				for (p = 1; p < i; p++) {
					dp[i][j] = max(dp[i][j], dp[p][j-1]*(sum[i]-sum[p]));
				} 
			} 
		} 
	} 
	printf("%lld",dp[n][k]);
	return 0;
}
