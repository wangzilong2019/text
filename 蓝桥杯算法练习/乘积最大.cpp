#include<stdio.h>
#define max(a,b) a>b?a:b
long long dp[42][8];//dp[i][j]��ʾi����j���˺ŵ����ֵ������ɾ����ʾ 
char c[42]; 
long long num(int a,int b){//����aλ����bλ���ַ�תΪ���� 
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
		dp[i][0]=num(1,i);//�������û�г˺����õ�dpֵ
	for(i=2;i<=n;i++){
		for(j=1;j<=k&&j<i;j++)//i��������ܼ���i-1���˺� 
		for(x=1;x<i;x++)//x��ʾ���˺Ų����λ�� ��x���ܴ���i
			dp[i][j]=max(dp[i][j],dp[x][j-1]*num(x+1,i)); //һֱȡ���ֵ 
	}
	printf("%d",dp[n][k]);
	return 0;
}
