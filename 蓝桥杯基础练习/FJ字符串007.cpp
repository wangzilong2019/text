#include<stdio.h>
void print(int n) {
	//�жϵݹ�����
	if (n == 1) {
		printf("A");
	} 
	else {
		print(n-1);
		printf("%c",'A'+n-1);
		print(n-1);
	}
}
int main () {
	int n;
	//����n�ĸ���
	scanf("%d",&n);
	//��ӡ�ַ��� 
	print(n); 
	return 0;
} 
