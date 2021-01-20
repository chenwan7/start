#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"Sysutil.h" //顺序表

#define ElemType int
#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 4


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
void SeqListPushBack(SeqList *pst, ElemType x);
void SeqListPushFront(SeqList *pst, ElemType x);
void SeqListShow(SeqList *pst);
void SeqListPopBack(SeqList *pst);
void SeqListPopFront(SeqList *pst);

size_t SeqListLength(SeqList *pst);
size_t SeqListCapacity(SeqList *pst);

void SeqListSort(SeqList *pst);
void SeqListInsertByVal(SeqList *pst, ElemType x);
void SeqListInsertByPos(SeqList *pst, int pos, ElemType x);
void SeqListDeleteByVal(SeqList *pst, ElemType key);
void SeqListDeleteByPos(SeqList *pst, int pos);

int SeqListFind(SeqList *pst, ElemType key);
void SeqListSort(SeqList *pst);
void SeqListReverse(SeqList *pst);
void SeqListRemoveAll(SeqList *pst, ElemType key);
void SeqListClear(SeqList *pst);
int SeqListFindByBinary(SeqList *pst, ElemType key);
void SeqListDestroy(SeqList *pst);

//函数定义
bool IsFull(SeqList *pst)
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList *pst)
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
//下划线代表这个函数只能是内部函数
//bool _Inc(SeqList *pst)
//{
//	//申请新空间
//	ElemType *new_base = (ElemType*)malloc(sizeof(ElemType)*(pst->capacity * 2));
//	if (new_base == NULL)
//	{
//		printf("扩容失败.\n");
//		return false;
//	}
//	//拷贝数据
//	memcpy(new_base, pst->base, sizeof(ElemType)*pst->capacity);
//
//	//释放旧空间
//	free(pst->base);
//
//	//更改base的指向
//	pst->base = new_base;
//	pst->capacity += SEQLIST_INC_SIZE;
//	return true;
//}


bool _Inc(SeqList *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*(pst->capacity + SEQLIST_INC_SIZE));
	if (new_base == NULL)
	{
		printf("扩容失败.\n");
		return false;
	}
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}

void SeqListPushBack(SeqList *pst, ElemType x)//1
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，%d 不能尾部插入。\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}
void SeqListPushFront(SeqList *pst, ElemType x)//2
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，%d 不能头部插入。\n", x);
		return;
	}
	for (int i = pst->size; i > 0; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[0] = x;
	pst->size++;

}

void SeqListShow(SeqList *pst)//3
{
	assert(pst);
	for (int i = 0; i<pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}
void SeqListPopBack(SeqList *pst)//4
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，不能尾部删除。\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList *pst)//5
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，不能头部删除。\n");
		return;
	}
	for (int i = 0; i<pst->size; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;

}
size_t SeqListLength(SeqList *pst)//6
{
	return pst->size;
}

size_t SeqListCapacity(SeqList *pst)//7
{
	return pst->capacity;
}

void SeqListInsertByVal(SeqList *pst, ElemType x)//8
{
	//插入之前要保证数据有序
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，%d 不能按值插入.\n", x);
		return;
	}

	//寻找位置插入
	int pos = 0;
	while (pos<pst->size && x>pst->base[pos])
		pos++;

	for (int i = pst->size; i>pos; --i)
		pst->base[i] = pst->base[i - 1];

	pst->base[pos] = x;
	pst->size++;
}

void SeqListInsertByPos(SeqList *pst, int pos, ElemType x)//9
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，%d 不能按位置插入.\n", x);
		return;
	}
	if (pos<0 || pos>pst->size)
	{
		printf("插入的位置非法，%d 不能按位置插入.\n", x);
		return;
	}

	for (int i = pst->size; i>pos; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}
void SeqListDeleteByVal(SeqList *pst, ElemType key)//10
{
	assert(pst);
	int index = SeqListFind(pst, key);
	if (index == -1)
	{
		printf("要删除的元素%d不存在，不能删除.\n", key);
		return;
	}
	//for(int i=index; i<pst->size; ++i)
	//	pst->base[i] = pst->base[i+1];
	//pst->size--;
	SeqListDeleteByPos(pst, index);
}

void SeqListDeleteByPos(SeqList *pst, int pos)//11
{
	//判断位置的合法性
	assert(pst && (pos >= 0 && pos<pst->size));
	for (int i = pos; i<pst->size; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}
int SeqListFind(SeqList *pst, ElemType key)//12
{
	for (int i = 0; i<pst->size; ++i)
	{
		if (key == pst->base[i])
			return i;
	}
	return -1;
}
void SeqListSort(SeqList *pst)//13
{
	//冒泡排序
	for (int i = 0; i<pst->size - 1; ++i) //控制趟数
	{
		for (int j = 0; j<pst->size - i - 1; ++j)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				//交换数据
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}
void SeqListReverse(SeqList *pst)//14
{
	assert(pst);
	int start = 0, end = pst->size - 1;
	while (start < end)
	{
		ElemType tmp = pst->base[start];
		pst->base[start] = pst->base[end];
		pst->base[end] = tmp;

		start++;
		end--;
	}
}
void SeqListRemoveAll(SeqList *pst, ElemType key)//15
{
	assert(pst);
	int index;
	do
	{
		index = SeqListFind(pst, key);
		if (index == -1)
			break;
		SeqListDeleteByPos(pst, index);
	} while (1);
}

void SeqListClear(SeqList *pst)//16
{
	pst->size = 0;
}
int SeqListFindByBinary(SeqList *pst, ElemType key)//18
{
	assert(pst);
	SeqListSort(pst); //先保证查找的数据有序

	int low = 0, high = pst->size - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == pst->base[mid])
			return mid;
		else if (key < pst->base[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

void SeqListDestroy(SeqList *pst)
{
	assert(pst);
	free(pst->base);
	pst->base = NULL; // 预防野指针
	pst->capacity = pst->size = 0;
}

#endif 