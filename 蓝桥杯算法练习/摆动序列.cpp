#include<stdio.h>
#define MAX 1000
int sum;  //记录可行解
int book[MAX] = {0};
int data[MAX] = {0};
int n;
//深度优先遍历找到可行解·
void dfs(int t) {
	int i;
	if (t > 2) {
		//若只有俩个数，则满足
		if (t == 3) {
			sum++;
		} 
		//若有俩个数字以上判断是否满足条件 
		else {
			//若满足条件 
			//注意判断乘机为正负一定要注意相同位置减相乘 
			if ((data[t-1]-data[t-3])*(data[t-2]-data[t-3]) < 0) {
				sum++;
			}
			//否则则退层找到满足条件的
			else {
				return ;
			} 
		}
	}
	//此段代码目的找到不相同的数字
	for (i = 1; i <= n; i++) {
		//设置标志域判断此数字是否被用过
		if (book[i] == 0) {
			book[i] = 1;
			data[t] = i;
			dfs(t+1);
			book[i] = 0; 
		} 
	} 
	//退层搜做更多分支
	return ; 
} 

int main () {
	//输入数字n
	scanf("%d", &n);
	//初始化
	sum = 0;
	dfs(1);
	printf("%d\n", sum); 
	return 0;
} 


