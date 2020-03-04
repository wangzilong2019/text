#include<stdio.h>
#define MAX 1000
int main() {
	int i, j;
	int n;
	int a[MAX];
	printf("请输入所要计算的阶乘n：\n");
	scanf("%d",&n);
	a[1] = 1;
	int digit = 1;  //用来计算结果位数
	int num = 0;
	for (i = 2; i <= n ; i++) {
		num = 0;
		for (j = 1; j <= digit; j++) {
			int temp = a[j]*i + num;  //计算每一位*i加进位的结果
			a[j] = temp % 10;
			num = temp / 10; //计算进位 
		}
		//若新结果长度大于原来结果长度，重新赋值 
		while (num) {
			digit++;
			a[digit] = num % 10;
			num /= 10;
	
		}	
	}
	for (i = digit; i >= 1; i--) {
		printf("%d",a[i]); 
	} 
	return 0;
}
