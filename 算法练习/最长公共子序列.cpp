#include<stdio.h>
#include<String.h> 
#define MAX 100 
int c[MAX][MAX];  //��¼����������г���
int b[MAX][MAX];  //��¼�����������
char s1[MAX];  //�ַ���s1
char s2[MAX];  //�ַ���s2
int len1,len2;  //��¼�����ַ�������
//����ӹ������г��� 
void LCSL() {
	int i,j;
	for(i = 1; i <= len1; i++){
		for(j = 1; j <= len2; j++){
			//�����ǰ�ַ���ͬ���򹫹������еĳ���Ϊ��ǰ�������������+1 
			if (s1[i-1] == s2[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1; 
			}
			else {
				//�����ߵ����ֵ����¼���Ž� 
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
//��������������
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
	printf("�������ַ���s1��");
	gets(s1);
	len1 = strlen(s1);
	printf("�������ַ���s2��");
	gets(s2);
	len2 = strlen(s2);
	//��ʼ��c[][]����
	for (int i = 0; i <= len1; i++){
		c[i][0] = 0;
	}
	for (int j = 0; j <= len2; j++){
		c[0][j] = 0;
	}
	//������������� 
	LCSL();
	printf("����������г���Ϊ��\n");
	printf("%d",c[len1][len2]);
	printf("\n");
	printf("�����������Ϊ��\n");
	print(len1,len2);
	return 0;
} 
