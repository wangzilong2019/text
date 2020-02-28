#include<stdio.h>
#define MAX 100
//定义每个零件加工时间结构体 
struct node {
	int x;  //在第一个机器上的加工时间 
	int y;  //在第二个机器上的加工时间 
}a[MAX];
int f1 = 0;  //零件在第一个机器加工结束时间
int f2 = 0;  // 零件在第二个机器加工结束时间
int n;  //待加工零件数
int x[MAX];  //计算可行排列
int bestx[MAX];  //计算最优排列 
int bestf = 8888;  //计算最优值 
//求最大值
int max(int a, int b) {
	return a > b ? a : b;
} 

//搜索函数
void backTrack(int t) {
	int i, j;
	//当前节点为叶子节点
	if (t > n) {
		for (i = 1; i <= n; i++) {
			bestx[i] = x[i]; 
		}
		bestf = f2;
		return ;
	} 
	else {
		for (i = t; i<= n; i++) {
			f1 += a[x[i]].x;
			int temp = f2;
			f2 = max(f1, f2) + a[x[i]].y;
			//限界条件
			if (f2 < bestf) {
				int tp = x[i];
				x[i] = x[t];
				x[t] = tp;
				backTrack(t+1);
				tp = x[i];
				x[i] = x[t];
				x[t] = tp;
			} 
			f1 -= a[x[i]].x;
			f2 = temp;
		}
	}
} 
int main() {
	int i, j;
	printf("请输入加工的零件数n：\n");
	scanf("%d",&n);
	printf("请输入每个零件在第一个机器和第二个机器上的加工时间：\n");
	for (i = 1; i <=n; i++) {
		scanf("%d %d",&a[i].x, &a[i].y);
		x[i] = i;
	}
	backTrack(1);
	printf("请输出最优加工时间bestf：\n");
	printf("%d\n",bestf);
	printf("请输出最有加工顺序：\n");
	for (i = 1; i <= n; i++) {
		printf("%d ",bestx[i]);
	}
	return 0;
} 
