#include<stdio.h>
#define MAX 101
int book[MAX] = {0};//book[i] = 0��ʾiδ��ʹ��
int num[MAX] = {0};
int m, n;

//��ӡ����
void print () {
	int i;
	for (i = 1; i <= m; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
} 

void backtrack(int t) {
	int i;
	//������Ҷ�ӽڵ�ʱ���
	if (t > m) {
		print();
	} else {
		for (i = 1; i <= n; i++) {
			//������δ��ʹ�ù�
			if (book[i] == 0) {
				//����Ѿ�ʹ��
				book[i] = 1;
				num[t] = i;
				backtrack(t + 1);
				//����
				book[i] = 0; 
			} 
		}
	}
}

int main () {
	int i;
	//����n��m
	scanf("%d %d", &n, &m);
	backtrack(1); 
	return 0;
} 
