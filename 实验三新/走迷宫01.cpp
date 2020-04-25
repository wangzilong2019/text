#include "stdio.h"
int	map[8][8]={{0, 0, 0, 1, 0, 0, 0, 0},{0, 1, 1, 1, 1, 1, 1, 1},{0, 0, 0, 1, 0, 0, 0, 1},{0, 1, 0, 1, 0, 1, 0, 1},{0, 1, 0, 0, 0, 1, 0, 1},{0, 1, 1, 1, 1, 1, 0, 1},{0, 1, 0, 0, 0, 1, 0, 0},{0, 1, 0, 0, 0, 0, 1, 0}};
int dep;
int count;
void search(int i,int j);  //路径寻找，要求使用递归

//判断路是否可以走
int check(int x, int y) {
	int i, j;
	int flag = 1;
	//如出界则走不通
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		flag = 0;
	} else {
		//有路但是路已经被走过
		if (map[x][y] != 0) {
			flag = 0;
		} 
	}
	return flag;
} 

//打印可行解
void print() {
	int i, j;
	for (i = 0; i < 8; i++) {
		printf("\n");
		for (j = 0; j < 8; j++) {
			printf("  %d", map[i][j]);
		}
	} 
} 


int main() {

	count = 0;  //记录可行解 
	dep = 2;
	map[0][0] = 1;
	search(0, 0);
	printf("\n共有%d种方案", count);
	return 0;
}

void search(int i, int j) { 
	//定义右、下、左、上四个方向 
	int fx[4] = {0, 1, 0, -1};
	int fy[4] = {1, 0, -1, 0};
	int k, xx, yy;
	//分别遍历四个方向
	for (k = 0; k < 4; k++) {
		//当前一步要走的坐标
		xx = i + fx[k];
		yy = j + fy[k];
		//若此路可以走
		if (check(xx, yy)) {
			map[xx][yy] = dep++;  //可走s设置2
			//到达终点输出
			if (xx == 7 && yy == 7) {
				count++;
				print();
			} else {
				search(xx, yy);
			}

		} 
	} 
	map[i][j] = 0; //回溯
    dep--;
	 
}
