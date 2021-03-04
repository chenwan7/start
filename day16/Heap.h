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
HeapElemType HeapTop(Heap *php);//ȡ�Ѷ�Ԫ��
void HeapRemove(Heap *php);//ɾ�Ѷ�Ԫ��

void HeapClear(Heap *php);
void HeapDestroy(Heap *php);

//�ڲ�����
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
	int j = start;        //�ӽڵ�
	int i = (j - 1) / 2;  //���ڵ�

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
	int i = start;      //���ڵ�
	int j = 2 * i + 1;  //i�ڵ��������

	HeapElemType tem = php->heap[i];
	while (j < php->size)//û�е�Ҷ�ӽڵ�
	{
		if (j + 1 < php->size && php->heap[j] > php->heap[i])//���������� && ��������С
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
	memset(php->heap, 0, sizeof(HeapElemType)*sz);//��ʼ��

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
	int curpos = n / 2 - 1;//�ҵ������������һ����֧
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
		printf("�ѿռ�������%d���ܲ���.\n", x);
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
		printf("�ѿռ��ѿգ�����ȡ�Ѷ�Ԫ�ء�\n");
		return;
	}
	return php->heap[0];
}

void HeapRemove(Heap *php)
{
	if (HeapEmpty(php))
	{
		printf("�ѿռ��ѿգ�����ɾ�Ѷ�Ԫ�ء�\n");
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
