#include<stdio.h>
int f(int m, int n) {
	//����Ь����С�ڽ�Ь����ʱ
	if (m < n) {
		return 0;
	} else {
		if (n == 0 && m == 0) {
			return 0;
		}
		//����0���˽�Ьʱ 
		if (n == 0) {
			return 1;
		} else {
			return f(m, n-1)+f(m-1,n); 
		}
	}
}
int main () {
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d", f(m, n));
	return 0;
} 
