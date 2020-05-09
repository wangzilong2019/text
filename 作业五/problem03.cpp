#include<stdio.h>
int count;
int a[10];

//判断是否满足题目条件
int check() {
	int join;  //用来临时记录前i位
	int i;
	int flag = 1;
	join = 0;
	for (i = 1; i <= 9; i++) {
		join = join * 10 + a[i];
		//若前i位除i不为0则终止
		if (join % i != 0) {
			flag = 0;
			break;
		} 
	} 
	return flag;
} 

//打印结果
void print() {
	int i;
	for (i = 1; i <= 9; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
} 


void backtrack(int t) {
	int temp, i;
	//当到达叶子节点时输出
	if (t > 9) {
		//若满足条件输出
		if (check()) {
			count++;
			print();
		}
		return ;
	} 
	for (i = t; i <= 9; i++) {
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
	int i;
	//初始化
	count = 0;
	for (i = 1; i <= 9; i++) {
		a[i] = i;
	}
	backtrack(1);
	printf("一共有%d种", count);
	return 0;
} 
