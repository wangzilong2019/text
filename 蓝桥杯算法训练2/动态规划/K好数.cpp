#include<stdio.h>
#define MOD 1000000007
int main () {
	long long i, j, z;
	long long l, k;
	long long dp[500][105] = {0};  //dp[i][j]表示i位数以j开头的k好数字数量 
	long long sum = 0;
	//输入k进制l位
	scanf("%lld %lld", &k, &l);
	for (j = 0; j < k; j++) {
		dp[1][j] = 1;  //当只有1位数时全都为k好数 
	} 
	for (i = 2; i <= l; i++) {
		for (j = 0; j < k; j++) {
			for (z = 0; z < k; z++) {
				//判断是否为K好数字
				if (z != j + 1 && z != j - 1) {
					dp[i][j] += dp[i][z];
					dp[i][j] %= MOD;
				} 
			}
		}
	} 
	for (j = 0; j < k; j++) {
		sum += dp[l][j];
	}
	printf("%lld", sum);
	return 0;
}
