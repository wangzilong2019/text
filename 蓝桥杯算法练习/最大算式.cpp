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
	long long dp[MAX][MAX] = {0};  //dp[i][j]����ǰi��������j���˺����˻� 
	//�������ֵĸ����ͻ��ִ��� 
	scanf("%d %d", &n, &k);
	//����ÿ������
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		temp += a[i];
		sum[i] = temp;
	} 
	for (i = 1; i <= n; i++) {
		dp[i][0] = sum[i];
	}
	//���ѭ������˺ŵĸ���
	for (j = 1; j <= k; j++) {
		//�˲�ѭ���������ָ���
		for (i = 1; i <= n; i++) {
			//�˺ŵĸ���С�����ֵĸ���
			if (j < i) {
				//�˲�ѭ������˺ŵ�λ��
				for (p = 1; p < i; p++) {
					dp[i][j] = max(dp[i][j], dp[p][j-1]*(sum[i]-sum[p]));
				} 
			} 
		} 
	} 
	printf("%lld",dp[n][k]);
	return 0;
}
