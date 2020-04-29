#include<stdio.h>
#define MAX 30001

//���������㷨
int partion(int a[], int low, int high) {
	int i, j, pivot, temp;
	i = low;
	j = high;
	pivot = a[low];
	while (i < j) {
		//��������ɨ��
		while (i < j && a[j] > pivot) {
			j--;
		} 
		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
		}
		//��������ɨ��
		while (i < j && a[i] <= pivot) {
			i++;
		} 
		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j--;
		}
	}
	return i; //���ػ�׼Ԫ��λ�� 
} 

void quickSort(int a[], int low, int high) {
	int mid;
	if (low < high) {
		mid = partion(a, low, high);
		quickSort(a, low, mid-1);
		quickSort(a, mid+1, high);
	}
}

int main () {
	int n, i, a[MAX];
	int sum = 0;
	int w, j;
	scanf("%d %d", &w, &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		//�Ż�
		if (w-a[i] < 5) {
			i--;
			n--;
			sum++;
		} 
	}
	quickSort(a, 0, n-1);
	
	i = 0;
	j = n-1;
	while (i <= j) {
		if ( a[i] + a[j] <= w) {
			i++;
			j--;
			sum++;
		} else if(i < j) {
			j--;
			sum++;
		} else if(i == j) {
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}
