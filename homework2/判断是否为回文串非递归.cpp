/************begin************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i, len, flag;
	char ch[100];    //存放键入的字符串
	scanf("%s",ch); //接受键入的字符串
	
	//求字符串长度
	len = strlen(ch);
	//设标志位假设为回文串
	flag = 1; 
	//判断是否为回文串
	for (i = 0; i < len/2; i++) {
		if (ch[i] != ch[len-1-i]) {
			flag = 0;
			break;
		}
	} 
	//判断标志位来检测
	if (flag) {
		printf("输入的是回文。");
	} 
	else {
		printf("输入的不是回文。");
	}
	return 0;
}


/************end************/
