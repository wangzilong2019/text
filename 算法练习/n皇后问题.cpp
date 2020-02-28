#include<stdio.h>
#include<math.h>
#define MAX 100
int n;  //记录皇后个数
int x[MAX];  //记录第i个元素的列号
int countn = 0;  //记录可行解的个数
//判断第t个皇后的是否可以放在位置
int place(int t) {
	int i;
	int ok = 1;
	//判断第t个皇后与前面的是否不同列不同斜线 
	for (i = 1; i < t; i++) {
		if (x[t] == x[i] || t-i == fabs(x[t]-x[i])) {
			ok = 0;
			break;
		}
	} 
	return ok;
} 
//搜索函数
void backTrack(int t) {
	int i, j;
	//当前节点为叶子节点，则找到一个可行解
	if (t > n) {
		countn++;
		printf("第%d中方案为：\n",countn);
		for (i = 1; i <= n; i++) {
			printf("%d ",x[i]);
		}
		printf("\n");
	} 
	else {
		//找到每个皇后在合适的列号
		for (i = 1; i <= n; i++) {
			x[t] = i;
			if (place(t)) {
				backTrack(t+1);
			}
		} 
	}
} 
int main() {
	printf("请输入皇后的个数n：\n");
	scanf("%d",&n);
	backTrack(1);
	return 0;
} 
