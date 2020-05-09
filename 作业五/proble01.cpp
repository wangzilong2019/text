
#include <stdio.h>
#include <string.h>
#include<math.h>
#define maxn 201
#define INF 9999
char c[maxn];  //瀛樻斁閿叆鐨勬暟瀛椾覆
int m; //鍔犲彿鏁伴噺

int min(int a, int b) {
	return a < b ? a : b;
}

int main() 
{   
	int join;
	int data[maxn][maxn];  //data[i][j]表示第i到j数组串的大小
	int dp[maxn][maxn];  //dp[i][j] 表示前i个数字串有j个加号的最小值 
	int i, j, k, len;
	scanf("%s %d",c,&m); //閿叆鏁板瓧涓插拰鍔犲彿鏁伴噺
	
	//求数字长度
	len = strlen(c);
	//初始化数组
	//memset(dp, INF, sizeof(dp));
	
	for (i = 0; i < len; i++) {
		for (j = 0; j <= m; j++) {
			dp[i][j] = INF;
		}
	}
	
	for (i = 0; i < len; i++) {
		join = 0;
		for (j = i; j < len; j++) {
			join = join * 10 + c[j] - '0';
			data[i][j] = join;
		}
	} 
	

	for (i = 0; i < len; i++) {
		dp[i][0] = data[0][i];
	}
	
	for (i = 0; i < len; i++) {
		for (j = 1; j <= m; j++) {
			for (k = 0; k < i; k++) {
				dp[i][j] = min(dp[k][j-1] + data[k+1][i], dp[i][j]);
			}
		}
	}
	
	printf("%d", dp[len-1][m]);
	
	return 0;
}
