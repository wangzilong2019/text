#include<stdio.h>
#define MAX 1001

//�����н�������
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
	//���������еĸ���
	scanf("%d",&n); 
	//���������е�ÿ��Ԫ��
	for (i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	} 
	//����ѯ�ʵĸ���m
	scanf("%d",&m);
	//�������ѯ��l��r��k
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d",&l[i], &r[i], &k[i]);
	} 
	
	//�Ե�k�����в�ѯ
	for (i = 1; i <= m; i++) {
		
		for (p = l[i], index = 0; p <= r[i]; p++) {
			temp[++index] = a[p];
		}
		//����
		sort(temp, index);
		printf("%d\n",temp[k[i]]);
		
	}  
	return 0;
}
