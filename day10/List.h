#ifndef _LIST_H_
#define _LIST_H_

#include"Sysutil.h"

typedef struct ListNode
{
	int data;
	struct ListNode *next;
	
}ListNode;

typedef ListNode* List;


 //ͷ�ڵ� :ʹ�㷨����ͳһ
void ListInit(List*head)
{
	*head = (ListNode *)malloc(sizeof(ListNode));
	*head != NULL;
	(*head)->next = NULL;
}
//β�巨
void ListCreate_Tail(List*head)
{
	ListNode *p = *head;
	for (int i = 1; i <= 10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

void ListShow(List head)
{
	ListNode *p = head->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");


}

void ListCreate(List *head)
{
	ListNode *p = *head;
	for (int i = 1; i <= 10; i++)
	{
		p = p->next = (ListNode*)malloc(sizeof(ListNode));
		assert(p != NULL);
		p->data = i;
		p->next = NULL;
	}

}


/*void ListInit(List*head)
{
*head == NULL;
}*/

/*//β�巨
void ListCreate_Tail(List*head)
{
	*head = (ListNode*)malloc(sizeof(ListNode));
	assert(*head != NULL);
	(*head)->data = 1;

	ListNode *p = *head;
	for (int i = 2; i <= 10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;   

		//�ڵ�������
		p->next = s;
		p = s;
	}
}*/


//ͷ�巨
void ListCreate_Head(List*head)
{
	*head = (ListNode*)malloc(sizeof(ListNode));
	assert(*head != NULL);
	(*head)->data = 1;
	(*head)->next = NULL;

	for (int i = 2; i <= 10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		s->next = *head;
		*head = s;
	}
}


/*void ListShow(List head)
{
	ListNode *p = head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");

}*/




#endif