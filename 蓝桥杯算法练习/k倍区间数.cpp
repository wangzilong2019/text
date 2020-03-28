#include<stdio.h>
#define MAX 1001

//对数列进行排序
void sort(int a[], int n) {
	int i, j, temp, index, min;
	for (i = 1; i <= n-1; i++) {
		index = 1;
		min = a[1];
		for (j = 2; j <= n-i+1; j++) {
			if (min > a[j]) {
				min = a[j];
				index = j;
			}
		}
		temp = a[index];
		a[index] = a[n-i+1];
		a[n-i+1] = temp;
		
	}
} 

int main () {
	int m, n, i, index, p;
	int a[MAX];
	int temp[MAX];
	int l[MAX], r[MAX], k[MAX];
	//输入数列中的个数
	scanf("%d",&n); 
	//输入数列中的每个元素
	for (i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	} 
	//输入询问的个数m
	scanf("%d",&m);
	//输入待查询的l，r，k
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d",&l[i], &r[i], &k[i]);
	} 
	
	//对第k数进行查询
	for (i = 1; i <= m; i++) {
		
		for (p = l[i], index = 0; p <= r[i]; p++) {
			temp[++index] = a[p];
		}
		//排序
		sort(temp, index);
		printf("%d\n",temp[k[i]]);
		
	}  
	return 0;
}
