#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 999 3
int count;
int x[MAX];  //记录可行解的位置x[i]表示再i行x[i]列

int n;//皇后个数
void backtrack(int k); //位置尝试，要求使用递归

//判断第t个皇后的是否满足放置条件
int check(int t) {
	int i;
	int flag = 1;
	//判断第t个元素与前t-1个元素是否同行列斜线 
	for (i = 1; i < t; i++) {
		if (x[i] == x[t] || t - i == fabs(x[t] - x[i])) {
			flag = 0;
			break;
		}
	}
	return flag;
} 

//打印结果 
void print() {
	int i;
	printf("\n");
	printf("\n");
	for (i = 1; i <= 8; i++) {
		printf("第%d皇后在%d列\n", i, x[i]);
	}
}









void backtrack(int k)   //位置尝试，要求使用递归
{
 	int i;
	//当找到一种方案时
	if (k > n) {
		//可行解总数加1
		count++;
		//输出可行解
		print();
		return ; 
	} 
	
	//确定每个皇后的位置
	for (i = 1; i <= n; i++) {
		//第t个皇后的在t行x[t]列 
		x[k] = i;
		//满足条件递归 
		if (check(k)) {
			backtrack(k + 1);
		}
	}   



}




int main()
{  
	int i;
	printf("请输入n：");
    scanf("%d",&n);
	count = 0;
	//计算可行解 
	backtrack(1);
	printf("\n");
	printf("一共有%d种方案", count); 
	return 0;



}
