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
	//��¼���ڵ㲢����
	char root = s2[len_s2-1];
	printf("%c",root);
	//�������������ҵ����ڵ������ 
	for (i = 0; i < len_s1; i++) {
		if (s1[i] == root) {
			index = i;
			break;
		}
	}
	//��ǰ�����зֳ�������
	//�ҵ�ǰ�����е�������ǰ�� 
	for (i = 0; i < index; i++) {
		s1_left[i] = s1[i];
	}
	s1_left[index] = '\0';
	len_left = index;
	//�ҵ�ǰ�����е�������ǰ�� 
	for (k = 0,i = index+1; i < len_s1; i++,k++) {
		s1_right[k] = s1[i];
	}
	s1_right[k] = '\0';
	len_right = k;
	//�����������г��Ƚ�ȡ��������
	//�ҵ��������е����������� 
	for (i = 0; i < len_left; i++) {
		s2_left[i] = s2[i];
	} 
	s2_left[len_left] = '\0';
	//�ҵ��������е����������� 
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
	//��������ͺ�������
	gets(s1);
	gets(s2);
	//����������
	dfs(s1, s2); 
	return 0;
} 
