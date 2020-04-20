#include<stdio.h>
#define MAX 101
int book[MAX] = {0};//book[i] = 0表示i未被使用
int num[MAX] = {0};
int m, n;

//打印排列
void print () {
	int i;
	for (i = 1; i <= m; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
} 

void backtrack(int t) {
	int i;
	//当到达叶子节点时输出
	if (t > m) {
		print();
	} else {
		for (i = 1; i <= n; i++) {
			//当此数未被使用过
			if (book[i] == 0) {
				//标记已经使用
				book[i] = 1;
				num[t] = i;
				backtrack(t + 1);
				//回溯
				book[i] = 0; 
			} 
		}
	}
}

int main () {
	int i;
	//输入n和m
	scanf("%d %d", &n, &m);
	backtrack(1); 
	return 0;
} 
