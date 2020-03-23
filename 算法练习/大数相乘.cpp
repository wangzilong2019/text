#include<stdio.h>
#include<string.h>
#define MAX 1000
int main () {
	int a[MAX] = {0};  //数组a用来存放结果 
	int i, j, m, n, k;
	char s1[MAX], s2[MAX];
	int len1, len2;
	int d = 0;  //初始化进位为0 
	//输入俩个待相乘的数字
	gets(s1);
	gets(s2);
	//分别求数字的位数
	len1 = strlen(s1);
	len2 = strlen(s2);
	//俩个数字相乘
	for (i = 0, k = len1 - 1;i < len1; i++, k--) {
		for (j = 0, n = len2 - 1; j < len2; j++, n--) {
			 m = i + j;
			 //计算相乘结果 
			 int temp = a[m] + (s1[k] - 48) * (s2[n] - 48) + d;
			 a[m] = temp % 10;
			 d = temp / 10;
		}
		while (d > 0) {
			m++;
			a[m] = a[m] + d % 10;
			d = d / 10;
		}
	} 
	for (i = m; i >= 0; i--) {
		printf("%d",a[i]);
	}
	return 0;
} 
