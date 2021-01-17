#include"Sysutil.h"//顺序表
 
#define ElemType int
#define SEQLIST_DEFAULT_SIZE 8

typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;

}SeqList;

//函数申明
bool IsFull(SeqList *pst);
bool IsEmpty(SeqList *pst);
void SeqListInit(SeqList *pst);
void SeqListPushBack(SeqList *pst,ElemType x);
void SeqListPushFront(SeqList *pst, ElemType x);
void SeqListShow(SeqList *pst);
void SeqListPopBack(SeqList *pst);
void SeqListPopFront(SeqList *pst);


//函数定义
bool IsFull(SeqList *pst)
{
	return pst->size >= pst->capacity;
}
bool IsFull(SeqList *pst)
{
	return pst->size == 0;
}

void SeqListInit(SeqList *pst)
{
	assert(pst);
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);//开辟空间成功
	memset(pst->base, 0, sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);//内存初始化
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}



void SeqListPushBack(SeqList *pst, ElemType x)
{
	assert(pst);
	if (IsFull(pst))
	{
		printf("顺序表已满，%d 不能尾部插入。\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}
void SeqListPushFront(SeqList *pst, ElemType x)
{
	assert(pst);
	if(IsFull(pst))
	{
		printf("顺序表已满，%d 不能头部插入。\n", x);
		return;
	}
	for (int i = pst->size; i > 0; --i)
	{
		pst->base[i] = pst->[i - 1];
	}
	pst->base[0] = x;
	pst->size++;
	
}

void SeqListShow(SeqList *pst)
{
	assert(pst);
	for (int i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}
void SeqListPopBack(SeqList *pst)
{



}
void SeqListPopFront(SeqList *pst)
{




}

