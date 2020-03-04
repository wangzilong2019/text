#include<stdio.h>
#define MAX 1000
int main() {
	int i, j;
	int n;
	int status[MAX] = {1};  //初始时设置灯全开
	printf("请输入灯和人的个数n：\n");
	scanf("%d",&n);
	//1号同学将灯全部关掉
	for (i = 1; i <= n; i++) {
		status[i] = 1 - status[i];
	} 
	//2号同学将灯序号为2的倍数的灯打开
	for (i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			status[i] = 1 - status[i];
		}
	} 
	//其余同学将灯序号为自己倍数的序号灯做相反操作
	for (i = 3; i <= n; i++) {
		//序号为i同学对灯进行操作
		for (j = 1; j <= n; j++) {
			if (j % i == 0) {
				status[j] = 1 - status[j];
			}
		} 
	} 
	//输出最终各个灯的状态
	for (i = 1; i <= n; i++) {
		printf("%d ",status[i]);
	} 
	return 0;
} 
