//对于公式求解数字，通过缩小范围
//关灯问题和每个数字的因子个数有关 
//i*i的因子数必定为奇数个， 
#include<stdio.h>
int main () {
	int a[10] = {0};
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				a[i-1]++;
			}
		}
	} 
	for (int i = 0; i < 10; i++) {
		printf("%d ",a[i]);
	}
	return 0;
} 
