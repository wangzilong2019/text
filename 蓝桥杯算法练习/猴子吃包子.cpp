#include<stdio.h>
int main () {
	int x, y, z, x1, y1, z1, p;
	int r, s, t;
	//��������
	scanf("%d %d %d %d %d %d %d", &x, &y, &z, &x1, &y1, &z1, &p);
	//�����������λ
	r = (x1*y*z + y1*x*z + z1*x*y) / (x*y*z);
	printf("%d.", r);
	//��¼β��
	s = (x1*y*z + y1*x*z + z1*x*y) % (x*y*z);
	//ѭ��������
	while (p--) {
		s = s*10;  //��β������10���Դ������õ���iλ 
		t = s/(x*y*z); //�õ�β����iλ 
		s = s%(x*y*z); //�õ�β������
		//�жϵ�Ϊ���һλ
		if (p == 0) {
			s = s*10/(x*y*z);
			//�ж��Ƿ�Ҫ��������
			if (s >= 5) {
				t++;
			}
			
			 
		} 
		//���
		printf("%d", t); 
	} 
	return 0;
}
