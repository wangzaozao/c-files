#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Queue
{
	int *pBase;
	int front;
	int rear;
}QUEUE;
void init(QUEUE *);
int full_queue(QUEUE*);
int en_queue(QUEUE *, int);
void traverse_queue(QUEUE*);
int empty_queue(QUEUE *);
int out_queue(QUEUE*, int *);
int main(void)
{
	QUEUE Q;
	int val;
	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);
	en_queue(&Q, 8);
	traverse_queue(&Q);
	if (out_queue(&Q, &val))
	{
		printf("出队成功，队列出队的元素是：%d\n", val);
	}
	else
		printf("出队失败！");
	traverse_queue(&Q);
	return 0;
}
void init(QUEUE *pQ)
{
	pQ->pBase = (int*)malloc(sizeof(int)* 6);
	pQ->front = 0;
	pQ->rear = 0;
}
int full_queue(QUEUE*pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return 1;
	else
		return 0;
}
int en_queue(QUEUE *pQ, int val)
{
	if (full_queue(pQ))
	{
		return 0;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return 1;
	}

}
void traverse_queue(QUEUE*pQ)
{
	int i = pQ->front;
	while (i != pQ->rear)
	{
		printf("%d  ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	return;
}
int empty_queue(QUEUE *pQ)
{
	if (pQ->front == pQ->rear)
		return 1;
	else
		return 0;
}
int out_queue(QUEUE*pQ, int *pVal)
{
	if (empty_queue(pQ))
	{
		return 0;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return 1;
	}
}