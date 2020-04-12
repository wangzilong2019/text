#include<stdio.h>
#define MAX 1000
int main () {
	float d1, c, d2, p;
	int n;
	float dis[MAX], price[MAX];
	float max_len, total, remain;
	int i, j;
	int flag = 1;
	//�����ܾ��롢����������ÿ������ʻ���롢������ÿ���ͼ۸񡢼���վ��
	scanf("%f %f %f %f %d", &d1, &c, &d2, &p, &n);
	max_len = c*d2;
	//������;����վ�����Լ��ͼ� 
	for (i = 1; i <= n; i++) {
		scanf("%f %f", &dis[i],&price[i]);
		if (dis[i]-dis[i-1] > max_len) {
			flag = 0;
			break;
		}
	} 
	if ( !flag ) {
		printf("No Solution");
		return 0;
	}
	//��ʼ�� 
	dis[0] = 0;
	price[0] = p;
	dis[n+1] = d1;
	price[n+1] = 0;
	for (i = 0; i <= n; i = j) { //iΪ��ǰ����վ��jΪ��һ���� ��jΪ��ǰ������ѭ��
		for (j = i+1; j <= n+1; j++) {
			//���������ʻ���ص��ȵ�ǰ���˵ļ���վ 
			if (dis[j]-dis[i] > max_len) {
				j--;
				break;
			}
			//�ҵ��ȵ�ǰ ���˵ļ���վ
			if (price[j] <= price[i]) {
				break;
			} 
		} 
		
		//����ҵ��ȵ�ǰ���˵ļ���վ
		if (price[j] <= price[i]) {
			total += ((dis[j]-dis[i])/d2 - remain)*price[i];
			remain = 0;
		} 
		
		//����Ҳ������ǲ��ܵ���
		else {
			total += (c- remain)*price[i];
			remain = c - (dis[j]-dis[i])/d2;
		} 
		
	}
	printf("%.2f", total);
	return 0;
}
