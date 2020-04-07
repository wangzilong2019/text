#include<stdio.h>
#include<string.h>
#define MAX 100
char s1[MAX], s2[MAX];

void dfs(char s1[], char s2[]) {
	char s1_left[MAX], s1_right[MAX];
	char s2_left[MAX], s2_right[MAX];
	int len_s2 = strlen(s2);
	int len_s1 = strlen(s1);
	int index, i, k; 
	int len_left, len_right;
	//记录根节点并输入
	char root = s2[len_s2-1];
	printf("%c",root);
	//在中序序列中找到根节点的索引 
	for (i = 0; i < len_s1; i++) {
		if (s1[i] == root) {
			index = i;
			break;
		}
	}
	//将前序序列分成俩部分
	//找到前序序列的左子树前序 
	for (i = 0; i < index; i++) {
		s1_left[i] = s1[i];
	}
	s1_left[index] = '\0';
	len_left = index;
	//找到前序序列的右子树前序 
	for (k = 0,i = index+1; i < len_s1; i++,k++) {
		s1_right[k] = s1[i];
	}
	s1_right[k] = '\0';
	len_right = k;
	//根据俩个序列长度截取后续序列
	//找到后序序列的左子树后序 
	for (i = 0; i < len_left; i++) {
		s2_left[i] = s2[i];
	} 
	s2_left[len_left] = '\0';
	//找到后序序列的右子树后序 
	for (k = 0, i = len_left; i < len_left+len_right; i++, k++) {
		s2_right[k] = s2[i];
	}
	s2_right[k] = '\0';
	if (len_left > 0) {
		dfs(s1_left, s2_left);
	} 
	if (len_right > 0) {
		dfs(s1_right, s2_right);
	}
}
int main () {
	//输入中序和后序序列
	gets(s1);
	gets(s2);
	//求中序序列
	dfs(s1, s2); 
	return 0;
} 
