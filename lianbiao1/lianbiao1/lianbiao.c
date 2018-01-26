#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node
{
	int data;//������
	struct Node*pNext;//ָ����
}NODE, *PNODE;
PNODE creat_list();
void traverse_list(PNODE);
int main(void)
{
	PNODE pHead = NULL;
	pHead = creat_list();
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
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("����������Ҫ���ɵ�����ڵ�ĸ�����len= ");
	scanf_s("%d", &len);
	for (i = 0; i<len; i++)
	{
		printf("�������%d���ڵ��ֵ", i + 1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("����ʧ�ܣ�������ֹ!\n");
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