#include<stdio.h>
int main () {
	int i, j, n;
	int a, b;
	//������������
	scanf("%d %d",&a, &b);
	for (i = a; i <= b; i++) {
		printf("%d=",i); 
		n = i;
		j = 2;
		while(n != j) {
			//Ѱ���������������� 
			for (j = 2; j < n; j++) {
				if (n%j == 0 && n != j) {
					printf("%d*",j);
					n /= j;
					break;
				}
			}
		}
		printf("%d\n",n);
	} 
	return 0;
}
