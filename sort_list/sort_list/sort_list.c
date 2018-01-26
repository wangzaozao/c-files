#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node*pNext;
}NODE, *PNODE;
PNODE creat_list();
void traverse_list(PNODE);
int list_length(PNODE pHead);
void sort_list(PNODE pHead);
int main(void)
{
	PNODE pHead = NULL;
	pHead = creat_list();
	traverse_list(pHead);
	sort_list(pHead);
	traverse_list(pHead);
	return 0;
}
PNODE creat_list(void)
{
	int len;
	int i;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入您需要生成的链表节点的个数：len=");
	scanf_s("%d", &len);
	printf("\n");
	for (i = 0; i < len; i++)
	{
		printf("请输入第%d个节点的值", i + 1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
}
int list_length(PNODE pHead)
{
	int len = 0;
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		len++;
		p = p->pNext;
	}
	return len;
}
void sort_list(PNODE pHead)
{
	PNODE p, q;
	int i, j, t, length;
	length = list_length(pHead);

	for (p = pHead->pNext, i = 0; i < length-1; i++, p = p->pNext)
	{
		for (q = p->pNext, j = i + 1; j < length; j++, q = q->pNext)
		{
			if (p->data>q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
}

