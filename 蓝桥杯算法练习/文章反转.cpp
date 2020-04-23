#include<stdio.h>
#include<string.h>
int main () {
	char a[1000000];
	int i, j, len, r;
	//输入字符串
	gets(a);
	//求字符串长度
	len = strlen(a);
	r = len;
	for (i = len-1; i >= 0; i--) {
		//以空格字符作为分隔符
		if (a[i] == ' ') {
			for (j = i+1;j < r; j++) {
				printf("%c", a[j]);
			}
			printf(" ");
			r = i;
		} 
	} 
	for (i = 0; i < r; i++) {
		printf("%c", a[i]);
	}
	return 0;
}
