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
	//创建头节点
	p = (node*)malloc(sizeof(node));
	p->next = NULL;
	//尾节点指向头节点
	r = p;
	ctn = 10;
	//创建单链表
	while (ctn--) {
		scanf("%d %d", &a, &b);
		//创建节点
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
