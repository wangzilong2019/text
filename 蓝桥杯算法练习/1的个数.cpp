#include<stdio.h>
int main () {
	int n;
	int i, ctn, d, m;
	ctn = 0;
	//��������
	scanf("%d",&n);
	//ѭ��������1�ĸ���
	for (i = 1; i <= n; i++) {
		m = i;
		while (m) {
			d = m % 10;
			m /= 10;
			if (d == 1) {
				ctn++;
			}
		}
	} 
	printf("%d\n",ctn);
	return 0;
} 
