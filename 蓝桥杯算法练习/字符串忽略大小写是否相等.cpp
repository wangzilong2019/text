#include<stdio.h>
#include<string.h>
#define MAX 61
//���ַ���ȫ��ת��ΪСд
void low(char a[]) {
	int len = strlen(a);
	int i;
	for (i = 0; i < len; i++) {
		if (a[i]>=65 && a[i]<=90) {
			a[i] = a[i]+32;
		}
	}
} 

//�ж�һ���ַ����е��ַ��Ƿ�����һ���ַ�����
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

//�ж��Ƿ�������Ŀ
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
	//���������ַ���
	scanf("%s %s",s1, s2); 
	//���ַ�������
	len1 = strlen(s1);
	len2 = strlen(s2);
	//�ж������ַ����Ƿ��ȵ�
	if (len1 != len2) {
		printf("no");
		return 0;
	} 
	//�Ƚ��ַ��ֺ�ת����Сд
	low(s1);
	low(s2); 
	//���ַ�������
	sort(s1);
	sort(s2); 
	if (check(s1,s2)) {
		printf("yes");
	}else {
		printf("no");
	}
	return 0;
}
