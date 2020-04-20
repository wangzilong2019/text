#include<stdio.h>
#define MAX 100
int n, m;
int a[MAX];
//����Ԫ��
void swap (int t, int i) {
	int temp = a[t];
	a[t] = a[i];
	a[i] = temp;
} 

//��ӡ����
void print () {
	int i;
	for (i = 1; i <= m; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
} 

//�����㷨
void backtrack(int t) {
	int i;
	//������Ҷ�ӽڵ�ʱ���
	if (t > m) {
		print();
	} else {
		for (i = t; i <= n; i++) {
			swap(t, i);
			backtrack(t + 1);
			swap(t, i);
		}
	}
} 

int main () {
	int i;
	//����n
	scanf("%d %d", &n, &m);
	//��ʼ��Ԫ��
	for (i = 1; i <= n; i++) {
		a[i] = i;
	}
	backtrack(1);
	return 0;
}
