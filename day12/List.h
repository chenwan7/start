#ifndef _LIST_H_
#define _LIST_H_

#include"Sysutil.h"
#define ElemType int

//��ͷ˫��ѭ������
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode *prev;
	struct DCListNode *next;
}DCListNode;

typedef struct DCList
{
	//DCListNode *head;
	DCListNode *first;
	DCListNode *last;
	size_t size;
}DCList;

DCListNode *_BuyDCListNode(ElemType x)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->next = s->prev = NULL;
	s->data = x;
	return;
}


void DCListInit(DCList *plist);
void DCListPushBack(DCList *plist,ElemType x);//1
void DCListPushFront(DCList *plist, ElemType x);//2
void DCListShow(DCList *plist);//3
void DCListPopBack(DCList*plist);//4
void DCListPopFront(DCList*plist);//5
size_t DCListLength(DCList*plist);//6

void DCListInsertByVal(DCList *plist, ElemType x);//8

void DCListDeleteByVal(DCList *plist, ElemType key);//10

DCListNode* DCListFind(DCList *plist, ElemType key);//12

void DCListReverse(DCList *plist);//14

void DCListClear(DCList*plist);//16
void DCListDestroy(DCList*plist);//17







void DCListInit(DCList *plist)
{
	assert(plist);
	DCListNode *s = _BuyDCListNode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size = 0;
}

void DCListPushBack(DCList *plist, ElemType x)//1
{
	assert(plist);
	DCListNode *s = _BuyDCListNode(x);
	s->prev = plist->last;
	plist->last->next = s;
	plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size++;
}

void DCListPushFront(DCList *plist, ElemType x)//2
{
	assert(plist);
	DCListNode *s = _BuyDCListNode(x);
	s->next=plist->first->next;
	plist->first->next->prev = s;

	plist->first->next = s;
	s->prev = plist->first;
	if (plist->last == plist->first)
		plist->last = s;

	plist->size++;
}
void DCListShow(DCList *plist)//3
{
	DCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over\n");
}


void DCListPopBack(DCList*plist)//4
{
	assert(plist);
	DCListNode *p = plist->last;
	if (p != plist->first)
	{
		plist->last = p->prev;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;

		free(p);
		plist->size--;
	}
}
void DCListPopFront(DCList*plist)//5
{
	assert(plist);
	DCListNode *p;
	if (plist->size == 0)
		return;
	p= plist->first->next;

	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	plist->size--;

}
size_t DCListLength(DCList*plist)//6
{
	return plist->size;
}

void DCListInsertByVal(DCList *plist, ElemType x)//8
{
	assert(plist);
	DCListNode *s = _BuyDCListNode(x);
	DCListNode *p = plist->first->next;
	while (p != plist->first && x > p->data)
		p = p->next;
	if (p == plist->first)
		plist->last = s;

	s->next = p;
	s->prev = p->prev;

	s->prev->next = s;
	s->next->prev = s;





}

void DCListDeleteByVal(DCList *plist, ElemType key)//10
{
	assert(plist);
	DCListNode *p = DCListFind(plist, key);
	if (p != NULL)
	{
		if (p == plist->last)
			plist->last = p->prev;

		p->prev->next = p->next;
		p->next->prev = p->prev;

		free(p);
		plist->size--;
	}

}

DCListNode* DCListFind(DCList *plist, ElemType key)//12
{
	assert(plist);
	DCListNode *p = plist->first->next;
	while (p != plist->first && p->data != key)
		p = p->next;
	if (p == plist->first)
		return NULL;
	return p;
}

void DCListReverse(DCList *plist)//14
{
	assert(plist);
	DCListNode *p, *q;
	if (plist->size <= 1)
		return;
	p = plist->first->next;
	q = p->next;
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	while (q != plist->first)
	{
		p = q;
		q = q->next;

		p->next = plist->first ->next;
		p->next->prev = p;
		p->prev = plist->first;
		p->prev->next = p;
	}
}

void DCListClear(DCList*plist)//16
{
	assert(plist);
	DCListNode *p = plist->first->next;
	if (plist->size == 0)
		return;
	while (p != plist->first)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = plist->first->next;
	}
	plist->size = 0;
	plist->last = plist->first;
}


void DCListDestroy(DCList*plist)//17
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->first = NULL;
	plist->size = 0;
}


























// **********************��ͷ������(���Զ�)*******************************
typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;

}SListNode;

typedef struct SList
{
	SListNode *head;
}SList;

void SListInit(SList *plist);

void SListPushBack(SList *plist, ElemType x);//1
void SListPushFront(SList *plist, ElemType x);//2
void SListShow(SList *plist);//3
void SListPopBack(SList *plist);//4
void SListPopFront(SList *plist);//5
int SListLength(SList *plist);//6

void SListInsertByVal(SList *plist, ElemType x);//8

void SListDeleteByVal(SList *plist, ElemType key);//10

SListNode* SListFind(SList *plist, ElemType key);//12
void SListSort(SList *plist);//13
void SListReverse(SList *plist);//14
void SListRemoveAll(SList *plist, ElemType key);//15
void SListClear(SList *plist);//16 �ͷű���Ľڵ�
void SListDestroy(SList *plist);//17 �ݻ�


SListNode* _Buynode()//��������ڵ�
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;
	s->next = NULL;
	return s;
}

void SListInt(SList *plist)
{
	plist->head = NULL;
}

void SListPushBack(SList *plist, ElemType x)//1
{
	assert(plist);
	SListNode *s = _Buynode();
	s->data = x;
	//��������β��
	SListNode *p = plist->head;
	//�������Ϊ�� ����ĵ�һ���ڵ�
	if (p == NULL){
		plist->head = s;
	}
	else{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	}
}

void SListPushFront(SList *plist, ElemType x)//2
{
	assert(plist);
	SListNode *s = _Buynode();
	s->data = x;
	s->next = plist->head;
	plist->head = s;
}

void SListShow(SList *plist)//3
{
	SListNode *p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over");
}

void SListPopBack(SList *plist)//4
{
	assert(plist);
	SListNode *p = plist->head;
	if (p != NULL)
	{
		if (p->next == NULL)
		{
			plist->head = NULL;
		}
		else
		{
			SListNode *pre = NULL;
			while (p->next != NULL)
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
		}
		free(p);
	}
}

void SListPopFront(SList *plist)//5
{
	assert(plist);
	SListNode *p = plist->head;
	if (p != NULL)
	{
		plist->head = p->next;
		free(p);
	}
}

int SListLength(SList *plist)//6
{
	assert(plist);
	int len = 0;
	SListNode *p = plist->head;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}


void SListInsertByVal(SList *plist, ElemType x)//8
{
	assert(plist);
	SListNode *s = _Buynode();
	s->data = x;
	if (plist->head == NULL)
		plist->head = s;
	else
	{
		SListNode *p = plist->head;
		SListNode *pre = NULL;
		while (p != NULL && x > p->data)
		{
			pre = p;
			p = p->next;
		}
		if (pre == NULL)//ͷ������
		{
			s->next = p;
			plist->head = s;
		}
		else
		{
			s->next = pre->next;
			pre->next = s;//�໭ͼ
		}

	}

}


void SListDeleteByVal(SList *plist, ElemType key)//10
{
	assert(plist);
	SListNode *p = plist->head;
	SListNode *pre = NULL;
	while (p != NULL && p->data != key)
	{
		pre = p;
		p = p->next;
	}
	if (p != NULL)//�ҵ�����ִ�� �����˳�
	{
		if (pre == NULL)//ɾ�����ǵ�һ���ڵ�
		{
			plist->head = p->next;
		}
		else
		{
			pre->next = p->next;
		}
		free(p);
	}

}



SListNode* SListFind(SList *plist, ElemType key)//12
{
	assert(plist);
	SListNode *p = plist->head;
	while (p != NULL && p->data != key)
	{
		p = p->next;
	}
	return p;
}

void SListSort(SList *plist)//13
{
	assert(plist);//���������޸�ָ��
	SListNode *p, *q;
	//�Ͽ�����
	if (plist->head == NULL || plist->head->next == NULL)
		return;
	p = plist->head->next;
	plist->head->next = NULL;
	//ѭ����ֵ����
	q = p;
	while (q != NULL)//һ��һ���Ͽ�����
	{
		q = q->next;
		SListNode *t = plist->head;
		SListNode *pre = NULL;
		while (t != NULL && p->data > t->data)//Ѱ�Ҳ���λ��
		{
			pre = t;
			t = t->next;//1.����tָ���
		}
		if (pre == NULL)
		{
			p->next = plist->head;
			plist->head = p;
		}
		else
		{
			p->next = pre->next;//2.�Ͽ�p p->nextָ���
			pre->next = p;//2.����
		}
		p = q;
	}

}

void SListReverse(SList *plist)//14
{
	assert(plist);
	SListNode *p, *q;
	if (plist->head->next == NULL)
		return;
	//1.�и�����
	p = plist->head->next;
	plist->head->next = NULL;
	//2.��ʣ��ڵ�һһͷ��
	q = p;
	while (q != NULL)
	{
		q = q->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}

void SListRemoveAll(SList *plist, ElemType key)//15
{
	assert(plist);
	SListNode *p = plist->head;
	SListNode *pre = NULL;
	if (plist->head == NULL)
		return;
	while (p != NULL)
	{
		if (p->data == key)
		{
			if (pre == NULL)
				plist->head = p->next;
			else
				pre->next = p->next;
			
			free(p);
		}
		else
			pre = p;
		if (pre == NULL)
			p = plist->head;
		else
		p = pre->next;
	}



}


void SListClear(SList *plist)//16
{
	assert(plist);

	//do
	//{
	//	SListNode *p = plist->head;
	//	plist->head = p->next;//����Ϊ�ջ����
	//	free(p);
	//} while (plist->head != NULL);

	SListNode *p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}

void SListDestroy(SList *plist)//17
{
	SListClear(plist);
}





//typedef struct ListNode
//{
//	int data;
//	struct ListNode *next;
//
//}ListNode;
//typedef ListNode* List;
//
//
////*****************ͷ�ڵ� :ʹ�㷨����ͳһ*******************
//void ListInit(List*head)
//{
//	*head = (ListNode *)malloc(sizeof(ListNode));
//	*head != NULL;
//	(*head)->next = NULL;
//}
////β�巨
//void ListCreate_Tail(List*head)
//{
//	ListNode *p = *head;
//	for (int i = 1; i <= 10; ++i)
//	{
//		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
//		assert(s != NULL);
//		s->data = i;
//		s->next = NULL;
//
//		p->next = s;
//		p = s;
//	}
//}
//
//void ListShow(List head)
//{
//	ListNode *p = head->next;
//	while (p != NULL)
//	{
//		printf("%d-->", p->data);
//		p = p->next;
//	}
//	printf("Over.\n");
//
//
//}
//
//void ListCreate(List *head)
//{
//	ListNode *p = *head;
//	for (int i = 1; i <= 10; i++)
//	{
//		p = p->next = (ListNode*)malloc(sizeof(ListNode));
//		assert(p != NULL);
//		p->data = i;
//		p->next = NULL;
//	}
//
//}


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
//void ListCreate_Head(List*head)
//{
//	*head = (ListNode*)malloc(sizeof(ListNode));
//	assert(*head != NULL);
//	(*head)->data = 1;
//	(*head)->next = NULL;
//
//	for (int i = 2; i <= 10; ++i)
//	{
//		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
//		assert(s != NULL);
//		s->data = i;
//
//		s->next = *head;
//		*head = s;
//	}
//}


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