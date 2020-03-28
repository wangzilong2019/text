#include<stdio.h>
int main () {
	int score, key;
	//ÊäÈë·ÖÊı
	scanf("%d",&score);
	key = score/10;
	switch (key) {
		case 9 :
		case 10 :
			printf("A\n");
			break;
		case 8 :
			printf("B\n");
			break;
		case 7 :
			printf("C\n");
			break;
		case 6 :
			printf("D\n");
			break;
		default :
			printf("E\n");
	} 
	return 0;
}
