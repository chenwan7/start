#ifndef _LIST_H_
#define _LIST_H_

#include"Sysutil.h"
#define ElemType int

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

#endif