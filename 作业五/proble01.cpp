
#include <stdio.h>
#include <string.h>
#include<math.h>
#define maxn 201
#define INF 9999
char c[maxn];  //存放键入的数字串
int m; //加号数量

int min(int a, int b) {
	return a < b ? a : b;
}

int main() 
{   
	int join;
	int data[maxn][maxn];  //data[i][j]��ʾ��i��j���鴮�Ĵ�С
	int dp[maxn][maxn];  //dp[i][j] ��ʾǰi�����ִ���j���Ӻŵ���Сֵ 
	int i, j, k, len;
	scanf("%s %d",c,&m); //键入数字串和加号数量
	
	//�����ֳ���
	len = strlen(c);
	//��ʼ������
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
