#include<stdio.h>
#define MAX 100
#include<string.h>
int m[MAX][MAX]={0};  //��¼i��j�������ٳ˷����� 
int s[MAX][MAX]={0};  //��¼�������λ�� 
int n;  //��¼����ĸ���
int p[MAX];  //��¼���������������
//������Ŵ���
void maxtrichain() {
	int i, j, d, k;
	for (d = 2; d <= n; d++) {
		for (i = 1; i <= n-d+1; i++) {
			j = i+d-1;
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for (k = i+1; k < j; k++) {
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] =k;
				}
			}
		}
	}
} 
//�������λ��
void print(int i, int j) {
	if (i == j) {
		printf("A[%d]",i);
		return ;
	}
	printf("(");
	print(i, s[i][j]);
	print(s[i][j]+1, j);
	printf(")");
} 
int main() {
	int i, j;
	printf("���������ĸ���n��\n");
	scanf("%d",&n);
	printf("������ÿ����������������һ�������������\n");
	for (i = 0; i <= n; i++) {
		scanf("%d",&p[i]);
	}
	maxtrichain();
	printf("��С��������ֵΪ��\n");
	printf("%d\n",m[1][n]);
	print(1, n); 
	return 0;
} 
