#include<stdio.h>
#define MAX 100

//�ҳ����������������ֵ 
float max(float a, float b) {
	return a > b ? a : b;
}

//�ҳ���������������Сֵ
float min(float a, float b) {
	return a < b ? a : b;
} 
 
int main () {
	float x1, x2, x3, x4;
	float y1, y2, y3, y4;
	float m1, m2, n1, n2;
	//�ֱ������������εĳ��Ϳ�
	scanf("%f %f %f %f",&x1, &y1, &x2, &y2);
	scanf("%f %f %f %f",&x3, &y3, &x4, &y4);
	//�ֱ���������ĳ���
    n1 = min(max(x1, x2), max(x3, x4));  //�� 
	n2 = min(max(y1, y2), max(y3, y4));  //�� 
	m1 = max(min(x1, x2), min(x3, x4));  //�� 
	m2 = max(min(y1, y2), min(y3, y4));  //�� 
	//�ж��Ƿ��������
	if (n2 > m2 && n1 > m1) {
		printf("%.2f\n", (n1-m1)*(n2-m2));
	} 
	else {
		printf("0.00\n");
	}
	return 0;
}
