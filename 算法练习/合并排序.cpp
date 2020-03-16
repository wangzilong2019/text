//�鲢����
//�ȷֽ⣬����Ȼ���ٺϲ� ����һ���ϲ� 
#include<stdio.h>
#define MAX 100
void merge(int a[], int low, int mid, int high) {
	int temp[MAX];  //������ʱ�������õ�Ԫ��
	int i = low;  //��ָ��
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high) {
		//��С������븨������temp�� 
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	} 
	//��������ʣ�µ�Ԫ�ظ��Ƶ�temp�� 
	while (i <= mid) {
		temp[k++] = a[i++]; 
	}
	while (j <= high) {
		temp[k++] = a[j++];
	}
	//��������ʱ����������õ����ݷ�������a��
	for (i = low, k = 0; i <= high; i++) {
		a[i] = temp[k++];
	} 
}
void mergeSort(int a[],int low,int high) {
	while(low < high) {
		int mid = (low + high) / 2;  //ȡ�е� 
		mergeSort(a, low, mid);  //����벿�ֺϲ����� 
		mergeSort(a,mid+1, high);  //���Ұ벿�ֺϲ����� 
		merge(a,low,mid,high);  //�ϲ������� 
	}
}
int main() {
	int i, n;
	int a[MAX]; 
	printf("��������������ֵĸ�����\n");
	scanf("%d",&n);
	printf("���������������֣�\n");
	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	mergeSort(a, 0, n-1);
	for (i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	return 0;
}
