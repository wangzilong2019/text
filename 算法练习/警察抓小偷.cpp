#include<stdio.h>
int main () {
	int x;
	//xΪС͵ 
	for (x = 1; x <= 4; x++) {
		if ((1 != x) + (3 == x) + (4 == x) + (4 != x) == 3) {
			printf("%d",x);
		} 
	}
	return 0;
} 
