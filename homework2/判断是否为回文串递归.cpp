/************begin************/
#include<stdio.h>
#include<string.h>
#define MAX 100 
char s[MAX];
int len; 
int isPalindrome(int i)  //回文判断函数
{ 
	//当判断完成后结束 
	if (len-2*i == 1 || len-2*i == 0) {
		return 1;
	} 
	//当不满足回文数要求时退出循环 
	if (s[i] != s[len-1-i]) {
		return 0;
	} 
	return isPalindrome(++i);
}
int main()//主函数
{
	int i;
	
	//输入字符串 
	gets(s);
	//求字符串长度 
	len = strlen(s);
	if (isPalindrome(0)) {
		printf("输入的是回文。");
	} 
	else {
		printf("输入的不是回文。");
	}
	return 0;
}


/************end************/
