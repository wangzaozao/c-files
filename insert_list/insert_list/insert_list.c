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
int insert_list(PNODE pHead, int pos, int val);
int main(void)
{
	PNODE pHead = NULL;
	pHead = creat_list();
	traverse_list(pHead);
	insert_list(pHead, 4, 100);
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
int insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p&&i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if (i>pos - 1 || NULL == p)
	{
		return 0;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("动态分配内存失败!\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return 0;
}

