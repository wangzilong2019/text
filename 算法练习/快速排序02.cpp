#include<stdio.h> 
int partion(int a[], int low, int high) {
	int i = low;
	int j = high+1;
	int x = a[low];
	while (1) {
		//��������ɨ��
		while (i < j && a[--j] >= x) ;
		//��������ɨ��
		while (a[++i] < x) ;
		if (i >= j) {
			break;
		}
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	//���û�׼Ԫ��
	int temp = a[j];
	a[j] = a[low];
	a[low] = temp;
	return j;
}
//��������
void quickSort(int a[], int i, int j) {
	int mid;
	if (i < j) { 
		mid = partion(a, i, j);
		//��������� 
		quickSort(a, i, mid-1); 
		//���������� 
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
	//��������
	quickSort(a, 0, n-1);
	//�������
	for (int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	} 
	return 0;
}
