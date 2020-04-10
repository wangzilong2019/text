#include<stdio.h>
int f(int m, int n) {
	//当还鞋人数小于借鞋人数时
	if (m < n) {
		return 0;
	} else {
		if (n == 0 && m == 0) {
			return 0;
		}
		//当有0个人借鞋时 
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
