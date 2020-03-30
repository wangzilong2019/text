#include<stdio.h>
int main () {
	int n, num, i;
	//输入待乘数字
	scanf("%d", &n);
	//求阶乘
	num = 1;
	for (i = n; i >= 1; i--) {
		num *= i;
		//若结尾有0则去掉
		if (num%10 == 0) {
			num /= 10;
		} 
		//只保留俩位
		if (num/100 > 0) {
			num %= 100;
		} 
	} 
	//输出最后一额非零数字
	printf("%d\n",num%10); 
	return 0;
}
