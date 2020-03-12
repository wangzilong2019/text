#include<stdio.h>
int main() {
	int n;
	int a[5] = {1,2,3,4,5};
	for (int i = 0; i < 5; i++) {
		for (int j = i+1; j < 5; j++) {
			for (int k = j+1; k < 5; k++) {
				printf("%d %d %d\n",a[i],a[j],a[k]);
			}
		}
	}
	return 0;
} 
