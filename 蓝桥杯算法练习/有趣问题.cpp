#include<stdio.h>
#define MAX 1001

//辗转相除法求最大公约数
int gcd(int a, int b) {
	int temp;
	//首先找到俩者大小
	if (a < b) {
		temp = b;
		b = a;
		a = temp;
	} 
	//辗转相除法求最大公约数
	while (a%b) {
		temp = a%b;
		a = b;
		b = temp;
	} 
	return b;
}
//求最小公倍数
int f(int a, int b) {
	int i, temp;
	//找到俩个数的最大值 
	if (a < b) {
		temp = b;
		b = a;
		a = temp;
	} 
	for (i = a;;i++) {
		if (i%a== 0 && i%b==0) {
			break;
		}
	}
	return i;
} 

int main () {
	int i, j, n, x;
	int a0[MAX], a1[MAX], b0[MAX], b1[MAX];
	int ctn[MAX] = {0};
	//输入次数 
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a0[i], &a1[i], &b0[i], &b1[i]);
	}
	for (j = 0; j < n; j++) {
		for (x = a1[j]; x <= b1[j]; x++) {
			if (gcd(x,a0[j])==a1[j] && f(x,b0[j])==b1[j]) {
				ctn[j]++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d\n",ctn[i]);
	}
}
