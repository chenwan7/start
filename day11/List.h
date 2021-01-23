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
void SListClear(SList *plist);//16 释放表里的节点
void SListDestroy(SList *plist);//17 摧毁


SListNode* _Buynode()//用于申请节点
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
	//查找链表尾部
	SListNode *p = plist->head;
	//如果链表为空 插入的第一个节点
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
		if (pre == NULL)//头部插入
		{
			s->next = p;
			plist->head = s;
		}
		else
		{
			s->next = pre->next;
			pre->next = s;//多画图
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
	if (p != NULL)//找到继续执行 否则退出
	{
		if (pre == NULL)//删除的是第一个节点
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
	assert(plist);//不交换；修改指向
	SListNode *p, *q;
	//断开链表
	if (plist->head == NULL || plist->head->next == NULL)
		return;
	p = plist->head->next;
	plist->head->next = NULL;
	//循环按值插入
	q = p;
	while (q != NULL)//一个一个断开链表
	{
		q = q->next;
		SListNode *t = plist->head;
		SListNode *pre = NULL;
		while (t != NULL && p->data > t->data)//寻找插入位置
		{
			pre = t;
			t = t->next;//1.先让t指向空
		}
		if (pre == NULL)
		{
			p->next = plist->head;
			plist->head = p;
		}
		else
		{
			p->next = pre->next;//2.断开p p->next指向空
			pre->next = p;//2.链接
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
	//1.切割链表
	p = plist->head->next;
	plist->head->next = NULL;
	//2.将剩余节点一一头插
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