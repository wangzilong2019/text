#include<stdio.h>
#define MOD 1000000007
int main () {
	long long i, j, z;
	long long l, k;
	long long dp[500][105] = {0};  //dp[i][j]��ʾiλ����j��ͷ��k���������� 
	long long sum = 0;
	//����k����lλ
	scanf("%lld %lld", &k, &l);
	for (j = 0; j < k; j++) {
		dp[1][j] = 1;  //��ֻ��1λ��ʱȫ��Ϊk���� 
	} 
	for (i = 2; i <= l; i++) {
		for (j = 0; j < k; j++) {
			for (z = 0; z < k; z++) {
				//�ж��Ƿ�ΪK������
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
