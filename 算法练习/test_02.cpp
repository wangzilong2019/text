#include<stdio.h>
int main() {
	for (int i = 1; i <= 46; i++) {
		for (int j = i+2; j <= 48; j++) {
			if (i*(i+1) - (i + (i+1)) + j*(j+1) - (j + (j+1)) == 2015-1225) {
				printf("%d\n",i);
			} 
		}
	}
	return 0;
}
