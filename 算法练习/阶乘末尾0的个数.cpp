#include<stdio.h>
#define MAX 1000
int main () {
	int n, i, j;
	int a[MAX];
	//��λ������0 
	int sum = 0;
	//λ����ʼ��Ϊһλ
	int digit = 1;
	int count = 0;
	a[1] = 1;
	scanf("%d",&n);
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= digit; j++) {
			int temp = a[j]*i + sum;
			a[j] = temp % 10;
			sum = temp / 10;
		}
		while (sum) {
			digit++;
			a[digit] = sum % 10;
			sum = sum / 10;
		}
	} 
	for (i = 1; i <= digit; i++) {
		if (a[i] == 0) {
			count++;
		}
		else {
			break;
		}
	}
	printf("���������ĩβ��%d��0\n",count);
	return 0;
}
