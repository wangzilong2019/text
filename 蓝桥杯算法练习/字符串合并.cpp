#include<stdio.h>
#include<string.h> 
#define MAX 200
int main () {
	int i, j;
	char s1[MAX], s2[MAX];
	int len1, len2;
	//输入俩个字符串
	gets(s1);
	gets(s2);
	//求俩个字符串的长度
	len1 = strlen(s1);
	len2 = strlen(s2);
	//合并字符串
	for (i = 0; i < len2; i++) {
		s1[len1+i] = s2[i];
	}
	s1[len1+len2] = '\0';
	puts(s1);
	return 0;
}
