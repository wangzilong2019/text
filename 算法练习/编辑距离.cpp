#include<stdio.h>
#include<String.h>
#define MAX 100
char s1[MAX],s2[MAX];  //记录俩个字符串
int d[MAX][MAX];   //记录最优编辑距离
int len1,len2;  //记录俩个字符串长度
//求俩个数值最小值
int min(int a, int b) {
	return a < b ? a : b;
} 
//求最短编辑距离
void editdistance() {
	int i,j;
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			//判断俩个字符是否相等
			int diff;
			if (s1[i-1] == s2[j-1]) {
				diff = 0;
			} 
			else {
				diff = 1;
			}
			//先求俩者最小值，再求三者最小值
			int temp = min(d[i-1][j] + 1, d[i][j-1] + 1);
			d[i][j] = min(temp, d[i-1][j-1] + diff); 
		}
	}
} 

int main() {
	int i,j;
	printf("请输入第一个字符串s1：\n");
	gets(s1);
	printf("请输入第二个字符串s2：\n");
	gets(s2);
	//记录俩个字符串长度
	len1 = strlen(s1);
	len2 = strlen(s2);
	//初始化d[][]矩阵
	for (i = 0; i <= len1; i++) {
		d[i][0] = i;
	} 
	for (j = 0; j <= len2; j++) {
		d[0][j] = j;
	}
	printf("字符串s1和s2的编辑距离是：\n");
	printf("%d",d[len1][len2]);
	return 0;
} 
