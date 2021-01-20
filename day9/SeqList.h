#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"Sysutil.h" //˳���

#define ElemType int
#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 4


typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;

}SeqList;

//��������
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

//��������
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
	assert(pst->base != NULL);//���ٿռ�ɹ�
	memset(pst->base, 0, sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);//�ڴ��ʼ��
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}
//�»��ߴ����������ֻ�����ڲ�����
//bool _Inc(SeqList *pst)
//{
//	//�����¿ռ�
//	ElemType *new_base = (ElemType*)malloc(sizeof(ElemType)*(pst->capacity * 2));
//	if (new_base == NULL)
//	{
//		printf("����ʧ��.\n");
//		return false;
//	}
//	//��������
//	memcpy(new_base, pst->base, sizeof(ElemType)*pst->capacity);
//
//	//�ͷžɿռ�
//	free(pst->base);
//
//	//����base��ָ��
//	pst->base = new_base;
//	pst->capacity += SEQLIST_INC_SIZE;
//	return true;
//}


bool _Inc(SeqList *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*(pst->capacity + SEQLIST_INC_SIZE));
	if (new_base == NULL)
	{
		printf("����ʧ��.\n");
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
		printf("˳���������%d ����β�����롣\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}
void SeqListPushFront(SeqList *pst, ElemType x)//2
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳���������%d ����ͷ�����롣\n", x);
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
		printf("˳����ѿգ�����β��ɾ����\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList *pst)//5
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ�����ͷ��ɾ����\n");
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
	//����֮ǰҪ��֤��������
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳���������%d ���ܰ�ֵ����.\n", x);
		return;
	}

	//Ѱ��λ�ò���
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
		printf("˳���������%d ���ܰ�λ�ò���.\n", x);
		return;
	}
	if (pos<0 || pos>pst->size)
	{
		printf("�����λ�÷Ƿ���%d ���ܰ�λ�ò���.\n", x);
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
		printf("Ҫɾ����Ԫ��%d�����ڣ�����ɾ��.\n", key);
		return;
	}
	//for(int i=index; i<pst->size; ++i)
	//	pst->base[i] = pst->base[i+1];
	//pst->size--;
	SeqListDeleteByPos(pst, index);
}

void SeqListDeleteByPos(SeqList *pst, int pos)//11
{
	//�ж�λ�õĺϷ���
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
	//ð������
	for (int i = 0; i<pst->size - 1; ++i) //��������
	{
		for (int j = 0; j<pst->size - i - 1; ++j)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				//��������
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
	SeqListSort(pst); //�ȱ�֤���ҵ���������

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
	pst->base = NULL; // Ԥ��Ұָ��
	pst->capacity = pst->size = 0;
}

#endif 