//���ڹ�ʽ������֣�ͨ����С��Χ
//�ص������ÿ�����ֵ����Ӹ����й� 
//i*i���������ض�Ϊ�������� 
#include<stdio.h>
int main () {
	int a[10] = {0};
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				a[i-1]++;
			}
		}
	} 
	for (int i = 0; i < 10; i++) {
		printf("%d ",a[i]);
	}
	return 0;
} 
