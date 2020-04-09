#include<stdio.h>
int sum (int n) {
	int i;
	int sumv = 0;
	for (i = 1; i < n; i++) {
		if (n%i == 0) {
			sumv += i;
		}
	}
	return sumv;
}
int main () {
	int a, b;
	//ÊäÈëaºÍb
	scanf("%d %d", &a, &b);
	if (sum(a)==b && sum(b)==a) {
		printf("yes");
	} else {
		printf("no");
	}
	return 0;
}
