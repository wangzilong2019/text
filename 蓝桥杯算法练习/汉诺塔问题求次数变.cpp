#include<stdio.h>
#include<math.h>
#define MAX 1000
int main () {
	float x;
	int i, j, n, a[MAX];
	float sum = 0;
	n = 1;
	i = 0;
	// ‰»Îx
	scanf("%f", &x);
	while (1) {
		if (fabs(x) < 1e-6) {
			break;
		}
		while (sum < x) { 
			n++;
			sum += (float)1/n;
		}
		a[i++] = n-1;
		scanf("%f", &x);
		sum = 0;
		n = 1;
	} 
	for (j = 0; j < i; j++) {
		printf("%d card(s)\n",a[j]);
	}
	return 0;
} 
