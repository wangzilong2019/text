#include<stdio.h>
#define MAX 12
int sum_day(int y, int m, int d) {
	int r[MAX] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int p[MAX] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day = 0;
	int i;
	//�жϴ��������껹��ƽ��
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
		for (i = 0; i < m-1; i++) {
			day += r[i];
		}
		day = day+d;
		return day;
	} 
	else {
		for (i = 0; i < m-1; i++) {
			day += p[i];
		}
		day = day+d;
		return day;
	} 
	
}
int main () {
	int y, m, d, rea;
	//����������
	scanf("%d %d %d",&y, &m,&d);
	int res = sum_day(y, m, d);
	printf("%d\n", res);
	return 0;
} 
