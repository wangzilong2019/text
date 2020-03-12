#include<stdio.h> 
int partion(int a[], int low, int high) {
	int i = low;
	int j = high+1;
	int x = a[low];
	while (1) {
		//从右向左扫描
		while (i < j && a[--j] >= x) ;
		//从左向右扫描
		while (a[++i] < x) ;
		if (i >= j) {
			break;
		}
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	//放置基准元素
	int temp = a[j];
	a[j] = a[low];
	a[low] = temp;
	return j;
}
//快速排序
void quickSort(int a[], int i, int j) {
	int mid;
	if (i < j) { 
		mid = partion(a, i, j);
		//左区间快排 
		quickSort(a, i, mid-1); 
		//右区间排序 
		quickSort(a, mid+1, j);
	}
} 
int main () {
	int a[9];
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	//快速排序
	quickSort(a, 0, n-1);
	//输出排序
	for (int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	} 
	return 0;
}
