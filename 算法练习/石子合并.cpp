#include<stdio.h>
#define MAX 100
#define INF 8888
int n;  //记录石子堆数
int a[MAX];  //记录每堆石子数量
int sum[MAX];  //记录前i堆石子总数量
int Max[MAX][MAX],Min[MAX][MAX];  //记录路边玩法第i到j堆石子最大和最小费用
int min_circular,max_circular;  //记录操场玩法最大和最小费用 
int max(int a,int b) {
	return a > b ? a : b;
}
int min(int a,int b) {
	return a < b ? a : b; 
}
//直线型石子合并 
void straight(int a[],int n) {
	int d,k,i,j;
	//首先从俩堆石子知道n堆
	for (d = 2; d <= n; d++) {
		for (i = 1; i <= n-d+1; i++) {
			j = i+d-1;
			Max[i][j] = -1;
			Min[i][j] = INF;
			//记录第i堆到j堆之间的石子总数 
			int temp = sum[j] - sum[i-1];
			for (k = i; k < j; k++) {
				Max[i][j] = max(Max[i][j], Max[i][k] + Max[k+1][j] + temp);
				Min[i][j] = min(Min[i][j], Min[i][k] + Min[k+1][j] + temp);
			}
		}
	} 
}
//圆形石子合并
void circular(int a[],int n) {
	int i,j;
	//将石子数进行倍增赋值
	for (i = 1; i <= n-1; i++) {
		a[n+i] = a[i];
	} 
	//计算倍增后的石子数费用
	n = 2*n -1;
	straight(a,n);
	n = (n+1)/2;
	//假设第1堆到n堆石子最大最小费用
	min_circular = Min[1][n];
	max_circular = Max[1][n];
	for (i = 2; i <= n; i++) {
		if (max_circular < Max[i][i+n-1]) {
			max_circular = Max[i][i+n-1];
		}
		if (min_circular > Min[i][i+n-1]) {
			min_circular = Min[i][i+n-1];
		}
	}
} 
int main() {
	int i;
	printf("请输入石子堆数n：\n");
	scanf("%d",&n);
	printf("请输入每堆石子的数量：\n");
	for (i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	sum[0] = 0;
	//初始化sum[i]
	for (i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i];
	}
	//初始化Min[i][j],Min[i][j]
	for (i = 1; i <= n; i++) {
		Min[i][i] = 0;
		Max[i][i] = 0;
	}
	straight(a,n);
	printf("路边玩法所得的最大费用为：%d\n",Max[1][n]);
	printf("路边玩法所得的最小费用为：%d\n",Min[1][n]);
	circular(a,n);
	printf("操场玩法所得的最大费用为：%d\n",max_circular);
	printf("操场玩法所得的最小费用为：%d\n",min_circular); 
	return 0;
} 
