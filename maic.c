#include<stdio.h>
#include<Windows.h>
#define MAX 100
typedef struct Node
{
	char data;
	struct Node *next;
}Linkstacknode;
typedef Linkstacknode *Linkstack;
void Initstack(Linkstack top)
{
	top->next = NULL;
}
int Push(Linkstack top, char x)
{
	Linkstacknode *temp;
	temp = (Linkstacknode*)malloc(sizeof(Linkstack));
	if (temp == NULL)
		return -1;
	else
	{
		temp->data = x;
		temp->next = top->next;
		top->next = temp;
		return 1;
	}
}
int Pop(Linkstack top, char *x)
{
	Linkstacknode *temp;
	temp = top->next;
	if (temp != NULL)
	{
		top->next = temp->next;
		*x = temp->data;
		free(temp);
		return 1;
	}
}
int Isempty(Linkstack top)
{
	if (top->next == NULL)
		return -1;
	else
		return 1;

}
int Ishuiwen()
{
	Linkstack S;
	char ch, temp;
	Initstack(S);
	printf("\n请输入字符序列：");
	ch = getchar();
	while (ch != '@')
	{
		Push(S, ch);
		ch = getchar();
	}
	do
	{
		ch = getchar();
		Pop(S, &temp);
		if (ch != temp)
		{
			return (-1);
			printf("\nNO");
		}
	} while (ch != '@' && !Isempty(S));
		if (ch == '@' && ch!= Isempty(S))
		{
			return 1;
			printf("\nYES");
		}
}
int main()
{
	void Initstack(Linkstack top);
	int Ishuiwen();
	system("pause");
	return 0;
}
