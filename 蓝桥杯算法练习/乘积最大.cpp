#include<stdio.h>
#define max(a,b) a>b?a:b
long long dp[42][8];//dp[i][j]表示i个数j个乘号的最大值，设想成矩阵表示 
char c[42]; 
long long num(int a,int b){//将第a位到第b位的字符转为数字 
	int i,sum=0;
	for(i=a;i<=b;i++)
		sum=sum*10+c[i-1]-'0';
	return sum;
}
int main(){
	int n,k,i,j,x;
	scanf("%d%d",&n,&k);
	scanf("%s",c);
	for(i=1;i<=n;i++)
		dp[i][0]=num(1,i);//填补矩阵中没有乘号有用的dp值
	for(i=2;i<=n;i++){
		for(j=1;j<=k&&j<i;j++)//i个数最多能加入i-1个乘号 
		for(x=1;x<i;x++)//x表示将乘号插入的位置 ，x不能大于i
			dp[i][j]=max(dp[i][j],dp[x][j-1]*num(x+1,i)); //一直取最大值 
	}
	printf("%d",dp[n][k]);
	return 0;
}
