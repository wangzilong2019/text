#include<stdio.h>
int main () {
	int i, n, a, b, c;
	//慢组题目为完全平方数三位数100-999即满足的平方根为10-31
	for (i = 10; i <= 31; i++) {
		//求这个数n
		n = i*i;
		//分别求三位数的数字
		c = n % 10;
		b = n /10 %10;
		a = n / 100;
		//判断是否满足只有俩位数字相同
		if (((a == b) + (b == c) + (a == c)) == 1) {
			printf("   %d",n);
		} 
	} 
	return 0;
} 
