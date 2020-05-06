#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int dep;  //记录步长数
int count;  //记录可行解数 
int map[MAX][MAX] = {0};


//判断点x， y是否可达
int check(int x, int y) {
	int i;
	int flag = 1;
	if (x < 1 || x > 5 || y < 1 || y > 5 || map[x][y] != 0) {
		flag = 0;
	}
	return flag;
} 

//打印结果
void print() {
	int i, j;
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			printf(" %d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
} 

void search(int x, int y) {
	int xx;
	int yy;
	int i;
	int fx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int fy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	//分别朝八个方向尝试
	for (i = 0; i < 8; i++) {
		xx = x + fx[i];
		yy = y + fy[i];
		//判断此点是否可以走通
		if (check(xx, yy)) {
			dep++;
			map[xx][yy] = dep;
			//判断是否到达终点
			if (dep == 25) {
				count++;
				//打印路径
				print();
			} else {
				search(xx, yy);
			}
			map[xx][yy] = 0;
			dep--;
		} 
	} 
	//回溯
 
}

int main () {
	count = 0;
	dep = 1;
	map[1][1] = 1;
	search(1, 1);
	printf("路径总数%d", count);
	return 0;
} 
