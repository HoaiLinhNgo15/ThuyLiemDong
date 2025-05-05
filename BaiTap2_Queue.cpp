#include <stdio.h>
#include <string.h>

typedef struct Node
{
	char Info;
	Node *link;
}Node;

typedef struct queue
{
	Node *pHead, *pTail;
}queue;

void Init(queue &q);
int Empty(queue &q);
void EnQueue(queue &q, char x);
char DeQueue(queue &q);

int main()
{
	queue kt;
	Init(kt);
	char str[50]; fflush(stdin);
	gets(str);
	int n = strlen(str);
	for (int i=0 ; i<n ; i++)
	{
		if(str[i] != '*')
			EnQueue(kt, str[i]);
		else 
			printf("%c", DeQueue(kt));
	}
	
	return 1;
}

void Init(queue &q)
{
	q.pHead=q.pTail= NULL;
}

int Empty(queue &q)
{
	if (q.pHead == NULL) return 1; // hàng d?i r?ng
	else
	return 0;
}

void EnQueue(queue &q, char x)
{
	Node * p;
	p=new Node;
	p->Info = x; p->link = NULL;
	if(q.pHead == NULL)
	{
		q.pHead= p ;
		q.pTail=q.pHead;
	}
	else
	{
		q.pTail->link= p;
		q.pTail= p;
	}
}

char DeQueue(queue &q)
{
	char x;
	if (!Empty(q))
	{
		Node *p;
		p=q.pHead;
		x=p->Info;
		q.pHead=p->link;
		delete(p);
	}
	return x;
}
