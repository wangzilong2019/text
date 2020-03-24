/**1、此题的解题思路首先联想到n皇后问题
   2、可以先放置黑皇后，黑皇后满足条件再放置白皇后、白皇后满足条件即为一个记录 

*/ 
#include<stdio.h>
#include<math.h>
#define MAX 1000
int posB[MAX];  //存放黑皇后的位置
int posW[MAX];  //存放白皇后的位置
int map[MAX][MAX];  //存放地图
int n;  //记录单种颜色的皇后个数
int ans = 0;  //用来记录可行的解数
//黑皇后放置完成后，放置白皇后
//判断白皇后的放置位置是否合法
int checkW(int cur) {
	int flag;
	int i;
	flag = 1;
	//判断第cur个皇后与前cur-1个是否同列同斜线
	for (i = 1; i < cur; i++) {
		if (posW[i] == posW[cur] || fabs(posW[cur] - posW[i]) == cur - i) {
			flag = 0;
			break;
		}
	} 
	return flag;
} 
void dfs_w(int cur) {
	int i, j;
	//判断是否到达叶子节点
	if (cur == n+1) {
		ans++;
	} 
	else {
		for (i = 1; i <= n; i++) {
			//判断放置位置是否被黑皇后放置 
			if (posB[cur] == i) {
				continue;
			}
			//判断当前位置是否合法 
			posW[cur] = i;
			if (map[cur][i] == 0) {
				continue;
			}
			//判断是否满足皇后放置规则
			if (checkW(cur)) {
				dfs_w(cur+1);
			} 
		}
	} 
} 
//判断黑皇后的放置位置是否合法
int checkB(int cur) {
	int flag;
	int i;
	flag = 1;
	//判断第cur个皇后与前cur-1个是否同列同斜线
	for (i = 1; i < cur; i++) {
		if (posB[i] == posB[cur] || fabs(posB[cur] - posB[i]) == cur - i) {
			flag = 0;
			break;
		}
	} 
	return flag;
} 
//拓展当前节点 
void dfs_b(int cur) {
	int i, j;
	//判断当前节点是否到达叶子节点
	if (cur == n+1) {
		//放置白皇后
		dfs_w(1);	
	} 
	else {
		//放置黑皇后
		for (i = 1; i <= n; i++) {
			//判断放置位置是否合法
			if (map[cur][i] == 0) {
				continue;
			} 
			//合法则记录放置元素的位置
			posB[cur] = i;
			//判断是否满足皇后放置规则
			if (checkB(cur)) {
				dfs_b(cur+1);
			} 
		} 
	}
} 
int main () {
	int i, j;
	//输入单种颜色皇后的个数
	scanf("%d",&n);
	//输入地图的路径
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d",&map[i][j]);
		}
	} 
	//先放置黑皇后
	dfs_b(1); 
	printf("%d",ans); 
	return 0;
}
