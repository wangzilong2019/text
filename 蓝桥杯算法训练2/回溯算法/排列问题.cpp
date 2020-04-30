#include<stdio.h>
#define MAX 1000
int a[MAX];
int map[MAX][MAX];
int n, k;
int count = 0;


int check() {
	int flag = 1;
	int k;
	for (k = 0; k < n - 1; k++) {
		if (map[a[k]][a[k+1]] == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

void print() {
	int i;
	//printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	
}

//��ȫ����
void backtrack(int t) {
	int temp, i;
	if (t >= n) {
		//ɸѡ����Լ������ 
		if (check()) {
			count++;
			if (count == k) {  //�����k������ 
				print();
			}
		}
		return ;
	} 
	for (i = t; i < n; i++) {
		temp = a[t];
		a[t] = a[i];
		a[i] = temp;
		//�ݹ�
		backtrack(t + 1);
		//����
		temp = a[t];
		a[t] = a[i];
		a[i] = temp; 
	}
} 

int main () {
	int i, j;
	//����n
	scanf("%d %d", &n, &k);
	//����Լ������
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
		a[i] = i;
	} 
	backtrack(0); 
	return 0;
} 
