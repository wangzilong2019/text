//归并排序
//先分解，排序，然后再合并 ，不一定合并 
#include<stdio.h>
#define MAX 100
void merge(int a[], int low, int mid, int high) {
	int temp[MAX];  //用于临时存放排序好的元素
	int i = low;  //左指针
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high) {
		//从小到大放入辅助数组temp中 
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	} 
	//将数组中剩下的元素复制到temp中 
	while (i <= mid) {
		temp[k++] = a[i++]; 
	}
	while (j <= high) {
		temp[k++] = a[j++];
	}
	//将数组临时数组中排序好的数据放入数组a中
	for (i = low, k = 0; i <= high; i++) {
		a[i] = temp[k++];
	} 
}
void mergeSort(int a[],int low,int high) {
	while(low < high) {
		int mid = (low + high) / 2;  //取中点 
		mergeSort(a, low, mid);  //对左半部分合并排序 
		mergeSort(a,mid+1, high);  //对右半部分合并排序 
		merge(a,low,mid,high);  //合并子区间 
	}
}
int main() {
	int i, n;
	int a[MAX]; 
	printf("请输入待排序数字的个数：\n");
	scanf("%d",&n);
	printf("请输入待排序的数字：\n");
	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	mergeSort(a, 0, n-1);
	for (i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	return 0;
}
