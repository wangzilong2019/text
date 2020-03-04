#include<stdio.h>
#include<math.h>
#define MAX 1000
#define MOD 1000000 
//此种方法每个数组元素中存数字长度大于1 
int main() {
	int a[MAX];
	int n;
	int i, j;
	int sum = 0;  //设置当前进位为0
	int start;
	printf("请输入要计算的阶乘n：\n");
	scanf("%d",&n);
	int m = log(n)*n/6+2;  //计算阶乘n的结果长度 
	a[1] = 1;
	for (i = 2; i <= m; i++) {
		a[i] = 0;
	}
	//外层循环计算阶乘
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			int temp = a[j]*i + sum;
			a[j] = temp % MOD;
			sum = temp / MOD;
		}
		if (sum != 0) {
			a[j] = sum;
		}
	} 
	//找到第一个不为零的数组元素 
	for (i = m; i >= 1; i--) {
		if (a[i] == 0) {
			continue;
		}
		else {
			start = i;
			break;
		}
	}
	for (i = start; i >= 1; i--) {
		printf("%d",a[i]);
	}
	return 0;
} 
