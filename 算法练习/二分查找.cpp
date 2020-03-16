#include<stdio.h>
#define MAX 100
//冒泡排序 
void sort(int a[],int n) {
	int i, j;
	//外层空值排序趟数 
	for (i = 0; i < n; i++) {
		//内层循环空值比较次数 
		for (j = 0; j <n-1-i; j++) { 
			if (a[j] > a[j+1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
int binarySearch(int a[],int n,int x) {
	int i = 0;  //左指针 
	int j = n-1;  //右指针
	while (i < j) {
		int mid = (i + j) / 2;
		if (x == a[mid]) {
			return mid;
		}
		else {
			if (a[mid] > x) {
				j = mid;
			}
			else {
				i = mid;
			}
		}
	} 
	return -1;
} 
int main () {
	int i,x,n,a[MAX];
	printf("请输入待查找数组中的数据个数n：\n");
	scanf("%d",&n);
	printf("请输入数组中的每个数据：\n");
	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	printf("请输入待查找数字x：\n");
	scanf("%d",&x);
	//将数组排序
	sort(a,n); 
	printf("排序后的数组元素为：\n");
	for (i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n待查找元素序号为：\n%d",binarySearch(a,n,x));
	
	return 0;
} 
