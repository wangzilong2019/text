#include<stdio.h>
#include<String.h> 
#define MAX 100 
int c[MAX][MAX];  //记录最长公共子序列长度
int b[MAX][MAX];  //记录最长公共子序列
char s1[MAX];  //字符串s1
char s2[MAX];  //字符串s2
int len1,len2;  //记录俩个字符串长度
//求最长子公共序列长度 
void LCSL() {
	int i,j;
	for(i = 1; i <= len1; i++){
		for(j = 1; j <= len2; j++){
			//如果当前字符相同，则公共子序列的长度为当前的最长公共子序列+1 
			if (s1[i-1] == s2[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1; 
			}
			else {
				//找俩者的最大值，记录最优解 
				if (c[i][j-1] >= c[i-1][j]) {
					c[i][j] = c[i][j-1];
					b[i][j] = 2;
				}
				else {
					c[i][j] = c[i-1][j];
					b[i][j] = 3;
				}
			}
		}
	}
} 
//输出最长公共子序列
void print(int i, int j) {
	if (i == 0 || j == 0) {
		return ;
	}
	if (b[i][j] == 1) {
		print(i-1,j-1);
		printf("%c",s1[i-1]);
	}
	else {
		if (b[i][j] == 2) {
			print(i,j-1); 
		}
		else {
			print(i-1,j);
		}
	}
} 
int main() {
	printf("请输入字符串s1：");
	gets(s1);
	len1 = strlen(s1);
	printf("请输入字符串s2：");
	gets(s2);
	len2 = strlen(s2);
	//初始化c[][]矩阵
	for (int i = 0; i <= len1; i++){
		c[i][0] = 0;
	}
	for (int j = 0; j <= len2; j++){
		c[0][j] = 0;
	}
	//求最长公共子序列 
	LCSL();
	printf("最长公共子序列长度为：\n");
	printf("%d",c[len1][len2]);
	printf("\n");
	printf("最长公共子序列为：\n");
	print(len1,len2);
	return 0;
} 
