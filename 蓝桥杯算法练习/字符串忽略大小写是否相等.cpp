#include<stdio.h>
#include<string.h>
#define MAX 61
//将字符串全部转化为小写
void low(char a[]) {
	int len = strlen(a);
	int i;
	for (i = 0; i < len; i++) {
		if (a[i]>=65 && a[i]<=90) {
			a[i] = a[i]+32;
		}
	}
} 

//判断一个字符串中的字符是否在另一个字符串中
void sort(char a[]) {
	int len = strlen(a);
	int i, j, temp;
	for (i = 1; i < len; i++) {
		for (j = 0; j < len-i; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

//判断是否满足题目
int check(char a[], char b[]) {
	int len = strlen(a);
	int i;
	int flag = 1;
	for (i = 0; i < len; i++) {
		if (a[i] != b[i]) {
			flag = 0;
			break;
		}
	}
	return flag;
} 
int main () {
	char s1[MAX], s2[MAX];
	int len1, len2;
	int i;
	//输入俩个字符串
	scanf("%s %s",s1, s2); 
	//求字符串长度
	len1 = strlen(s1);
	len2 = strlen(s2);
	//判断俩个字符串是否先等
	if (len1 != len2) {
		printf("no");
		return 0;
	} 
	//先将字符粗汉转换成小写
	low(s1);
	low(s2); 
	//将字符串牌序
	sort(s1);
	sort(s2); 
	if (check(s1,s2)) {
		printf("yes");
	}else {
		printf("no");
	}
	return 0;
}
