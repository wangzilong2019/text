#include<stdio.h>
#define MAX 100
int n, m;
int a[MAX];
//交换元素
void swap (int t, int i) {
	int temp = a[t];
	a[t] = a[i];
	a[i] = temp;
} 

//打印排列
void print () {
	int i;
	for (i = 1; i <= m; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
} 

//排列算法
void backtrack(int t) {
	int i;
	//当到达叶子节点时输出
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
	//输入n
	scanf("%d %d", &n, &m);
	//初始化元素
	for (i = 1; i <= n; i++) {
		a[i] = i;
	}
	backtrack(1);
	return 0;
}
