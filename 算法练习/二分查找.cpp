#include<stdio.h>
#define MAX 100
//ð������ 
void sort(int a[],int n) {
	int i, j;
	//����ֵ�������� 
	for (i = 0; i < n; i++) {
		//�ڲ�ѭ����ֵ�Ƚϴ��� 
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
	int i = 0;  //��ָ�� 
	int j = n-1;  //��ָ��
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
	printf("����������������е����ݸ���n��\n");
	scanf("%d",&n);
	printf("�����������е�ÿ�����ݣ�\n");
	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	printf("���������������x��\n");
	scanf("%d",&x);
	//����������
	sort(a,n); 
	printf("����������Ԫ��Ϊ��\n");
	for (i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n������Ԫ�����Ϊ��\n%d",binarySearch(a,n,x));
	
	return 0;
} 
