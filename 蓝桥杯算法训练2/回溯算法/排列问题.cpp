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

//求全排列
void backtrack(int t) {
	int temp, i;
	if (t >= n) {
		//筛选满足约束条件 
		if (check()) {
			count++;
			if (count == k) {  //输出第k个排列 
				print();
			}
		}
		return ;
	} 
	for (i = t; i < n; i++) {
		temp = a[t];
		a[t] = a[i];
		a[i] = temp;
		//递归
		backtrack(t + 1);
		//回溯
		temp = a[t];
		a[t] = a[i];
		a[i] = temp; 
	}
} 

int main () {
	int i, j;
	//输入n
	scanf("%d %d", &n, &k);
	//输入约束条件
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
		a[i] = i;
	} 
	backtrack(0); 
	return 0;
} 
