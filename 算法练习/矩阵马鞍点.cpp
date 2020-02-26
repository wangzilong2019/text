#include<stdio.h>
int main() {
	int a[5][5];
	int i,j;
	int k = 1;
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 5-i; j++) {
			a[i+j-1][j] = k;
			k++;
		}
	}
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
