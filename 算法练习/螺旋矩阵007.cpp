#include<stdio.h>
#define MAX 7
int main () {
	int a[MAX][MAX] = {0};
	int i, j;
	int n = 4;
	int top = 0;
	int left = 0;
	int right = 0;
	int bot = 0;
	int count = 1;
	while (n) {
		n--;
		//��������
		for (j = left; j < 7-1-right; j++) {
			a[top][j] = count;
			count++;
		} 
		top++;
		//���ϵ���
		for (i = top-1; i < 7-1-bot; i++) {
			a[i][7-1-right] = count;
			count++;
		} 
		right++;
		//���ҵ���
		for (j = 7-right; j > left; j--) {
			a[7-1-bot][j] = count;
			count++;
		} 
		bot++;
		//���µ���
		for (i = 7-bot; i > top-1; i-- ) {
			a[i][left] = count;
			count++;
		} 
		left++;
		if (n == 1) {
			a[7/2][7/2] = count;
		}
	}
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
