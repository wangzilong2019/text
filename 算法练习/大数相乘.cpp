#include<stdio.h>
#include<string.h>
#define MAX 1000
int main () {
	int a[MAX] = {0};  //����a������Ž�� 
	int i, j, m, n, k;
	char s1[MAX], s2[MAX];
	int len1, len2;
	int d = 0;  //��ʼ����λΪ0 
	//������������˵�����
	gets(s1);
	gets(s2);
	//�ֱ������ֵ�λ��
	len1 = strlen(s1);
	len2 = strlen(s2);
	//�����������
	for (i = 0, k = len1 - 1;i < len1; i++, k--) {
		for (j = 0, n = len2 - 1; j < len2; j++, n--) {
			 m = i + j;
			 //������˽�� 
			 int temp = a[m] + (s1[k] - 48) * (s2[n] - 48) + d;
			 a[m] = temp % 10;
			 d = temp / 10;
		}
		while (d > 0) {
			m++;
			a[m] = a[m] + d % 10;
			d = d / 10;
		}
	} 
	for (i = m; i >= 0; i--) {
		printf("%d",a[i]);
	}
	return 0;
} 
