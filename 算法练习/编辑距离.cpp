#include<stdio.h>
#include<String.h>
#define MAX 100
char s1[MAX],s2[MAX];  //��¼�����ַ���
int d[MAX][MAX];   //��¼���ű༭����
int len1,len2;  //��¼�����ַ�������
//��������ֵ��Сֵ
int min(int a, int b) {
	return a < b ? a : b;
} 
//����̱༭����
void editdistance() {
	int i,j;
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			//�ж������ַ��Ƿ����
			int diff;
			if (s1[i-1] == s2[j-1]) {
				diff = 0;
			} 
			else {
				diff = 1;
			}
			//����������Сֵ������������Сֵ
			int temp = min(d[i-1][j] + 1, d[i][j-1] + 1);
			d[i][j] = min(temp, d[i-1][j-1] + diff); 
		}
	}
} 

int main() {
	int i,j;
	printf("�������һ���ַ���s1��\n");
	gets(s1);
	printf("������ڶ����ַ���s2��\n");
	gets(s2);
	//��¼�����ַ�������
	len1 = strlen(s1);
	len2 = strlen(s2);
	//��ʼ��d[][]����
	for (i = 0; i <= len1; i++) {
		d[i][0] = i;
	} 
	for (j = 0; j <= len2; j++) {
		d[0][j] = j;
	}
	printf("�ַ���s1��s2�ı༭�����ǣ�\n");
	printf("%d",d[len1][len2]);
	return 0;
} 
