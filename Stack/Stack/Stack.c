#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node*pNext;
}NODE,*PNODE;
typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;//STACK相当于struct Stack,PSTACK相当于struct Stack*
void init(PSTACK);
void push(PSTACK pS, int val);
void traverse(PSTACK pS);
int empty(PSTACK pS);
int pop(PSTACK pS, int *val);
void clear(PSTACK pS);
int main(void)
{
	STACK S;
	int val;

	init(&S);
	push(&S,1);
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	push(&S, 6);	
	push(&S, 7);
	traverse(&S);
	clear(&S);
	traverse(&S);
	   if (pop(&S, &val))
		{
			printf("出栈成功，出栈的元素是%d\n", val);
		}
		else
		{
			printf("出栈失败！\n");
		}
	//while (!empty(&S))
	//{
	//	if (pop(&S, &val))
	//	{
	//		printf("出栈成功，出栈的元素是%d\n", val);
	//	}
	//	else
	//	{
	//		printf("出栈失败！\n");
	//	}
	//}

	return 0;
}
void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
}
void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	return;
}
void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != pS->pBottom)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}
int empty(PSTACK pS)
{
	if (pS->pBottom == pS->pTop)
		return 1;
	else
	    return 0;
}
int pop(PSTACK pS, int *val)
{
	if (empty(pS))
	{
		return 0;
	}
	else
	{
		PNODE r = pS->pTop;
		*val = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		return 1;
	}
}
void clear(PSTACK pS)
{
	if (empty(pS))
	{
		 return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;
		while (p != pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
}