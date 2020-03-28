#include<stdio.h>
#define MAX 10
void sort(int a[], int n) {
	int i, j, temp, index, max;
	for (i = 0; i < n-1; i++) {
		index = 0;
		max = a[0];
		for (j = 1; j < n-i; j++) {
			if (max < a[j]) {
				max = a[j];
				index = j;
			}
		}
		temp = a[index];
		a[index] = a[n-1-i];
		a[n-1-i] = temp;
	} 
}
int main () {
	int i, index;
	int a[MAX];
	//输入数据
	for (i = 0; i < 10; i++) {
		scanf("%d",&a[i]);
	} 
	//对数组排序
	sort(a, 10);
	index = 0;
	for (i = 1; i < 10; i++) {
		if (a[i] != a[index]) {
			index++;
			a[index] = a[i];
		}
	} 
	//输出
	for (i = 0; i <= index; i++) {
		printf("%d\n",a[i]);
	} 
	return 0;
}
