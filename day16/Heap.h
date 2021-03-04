#ifndef _HEAP_H_
#define _HEAP_H_

#include"Sysutil.h"


#define HeapElemType int

typedef struct Heap
{
	HeapElemType  *heap;
	size_t capacity;
	size_t size;

}Heap;


void HeapInit(Heap *php,int sz);
void HeapInitByArray(Heap *php, HeapElemType *ar, int n);
void HeapInsert(Heap *php, HeapElemType x);
void HeapShow(Heap *php);
HeapElemType HeapTop(Heap *php);//取堆顶元素
void HeapRemove(Heap *php);//删堆顶元素

void HeapClear(Heap *php);
void HeapDestroy(Heap *php);

//内部方法
void _AdjustUp(Heap *php, int start);
void _AdjustDown(Heap *php, int start);


bool HeapFull(Heap *php)
{
	return php->size >= php->capacity;
}

bool HeapEmpty(Heap *php)
{
	return php->size == 0;
}
void _AdjustUp(Heap *php, int start)
{
	int j = start;        //子节点
	int i = (j - 1) / 2;  //父节点

	HeapElemType tem = php->heap[j];

	while (j > 0)
	{
		if (php->heap[j] < php->heap[i])
		{
			php->heap[j] = php->heap[i];

			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	php->heap[j] = tem;
}

void _AdjustDown(Heap *php, int start)
{
	int i = start;      //父节点
	int j = 2 * i + 1;  //i节点的左子树

	HeapElemType tem = php->heap[i];
	while (j < php->size)//没有到叶子节点
	{
		if (j + 1 < php->size && php->heap[j] > php->heap[i])//右子树存在 && 右子树较小
			j = j + 1;
		if (tem > php->heap[j])
		{
			php->heap[i] = php->heap[j];

			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	php->heap[i] = tem;


}

void HeapInit(Heap *php,int sz)
{
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType)*sz);
	assert(php->heap != NULL);
	memset(php->heap, 0, sizeof(HeapElemType)*sz);//初始化

	php->capacity = sz;
	php->size = 0;

}
void HeapInitByArray(Heap *php, HeapElemType *ar, int n)
{
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType)*n);
	assert(php->heap != NULL);
	php->capacity = n;
	php->size = n;
	for (int i = 0; i < n; ++i)
		php->heap[i] = ar[i];
	int curpos = n / 2 - 1;//找到二叉树的最后一个分支
	while (curpos >= 0)
	{
		_AdjustDown(php, curpos);
		curpos--;
	}
}

void HeapInsert(Heap *php, HeapElemType x)
{
	if (HeapFull(php))
	{
		printf("堆空间已满，%d不能插入.\n", x);
		return;
	}
	php->heap[php->size] = x;
	_AdjustUp(php, php->size);
	php->size++;
}

void HeapShow(Heap *php)
{
	for (int i = 0;i < php->size; ++i)
	{
		printf("%d-", php->heap[i]);
	}
	printf("NULL\n");
}

HeapElemType HeapTop(Heap *php)
{
	if (HeapEmpty(php))
	{
		printf("堆空间已空，不能取堆顶元素。\n");
		return;
	}
	return php->heap[0];
}

void HeapRemove(Heap *php)
{
	if (HeapEmpty(php))
	{
		printf("堆空间已空，不能删堆顶元素。\n");
		return;
	}
	php->size--;
	php->heap[0] = php->heap[php->size];
	_AdjustDown(php, 0);

}

void HeapClear(Heap *php)
{
	php->size = 0;
}
void HeapDestroy(Heap *php)
{
	free(php->heap);
	php->heap = NULL;
	php->capacity = php->size = 0;
}

#endif
