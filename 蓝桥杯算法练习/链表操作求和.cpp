#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int a;
	int b;
	struct node *next;
}node, *list;
int main () {
	node *s,*r,*h;
	list p;
	int ctn, a, b;
	int x, y;
	//����ͷ�ڵ�
	p = (node*)malloc(sizeof(node));
	p->next = NULL;
	//β�ڵ�ָ��ͷ�ڵ�
	r = p;
	ctn = 10;
	//����������
	while (ctn--) {
		scanf("%d %d", &a, &b);
		//�����ڵ�
		s = (node*)malloc(sizeof(node));
		s->a = a;
		s->b = b;
		s->next = NULL;
		r->next = s;
		r = s; 
	} 
	x = 0;
	y = 0;
	h = p->next;
	while (h) {
		x = x+h->a;
		y = y+h->b;
		h = h->next;
	}
	printf("%d+%di",x, y);
	return 0;
}
