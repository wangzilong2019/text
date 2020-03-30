#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//����ת��
int reverse(int n) {
	int i = 0;
	char a[MAX];
	//�Ƚ��������������ַ�����
	while (n) {
		a[i++] = n%10+'0';
		n /= 10;
	} 
	//���ַ���������
	a[i] = '\0';
	n = atoi(a);
	return n; 
} 

//������ת�������
int reverse_sum (int a, int b) {
	int sum;
	a = reverse(a);
	b = reverse(b);
	sum = a+b;
	return sum;
} 

int main () {
	int a, b, sum;
	//������������
	scanf("%d %d",&a, &b);
	//����ת�� 
	sum = reverse_sum(a, b);
	sum = reverse(sum);
	printf("%d\n",sum);
	return 0;
}
