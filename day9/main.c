#include"SeqList.h"
#pragma warning (disable: 4996)
int main()
{
	SeqList mylist;
	SeqListInit(&mylist);

	ElemType item, key;
	int pos;

	int select = 1;
	while (select)
	{
		printf("**********************************\n");
		printf("*[1]pushback       [2]pushfront  *\n");
		printf("*[3]showlist       [4]popback    *\n");
		printf("*[5]popfront       [6]length     *\n");
		printf("*[7]capacity       [8]insertval  *\n");
		printf("*[9]insertpos      [10]deleteval *\n");
		printf("*[11]deletepos     [12]find      *\n");
		printf("*[13]sort          [14]reverse   *\n");
		printf("*[15]removeall     [16]clear     *\n");
		printf("*[17]destroy       [18]findbinary*\n");
		printf("*[0]quitsystem                   *\n");
		printf("**********************************\n");
		printf("��ѡ��>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("���������ݣ���-1������>");
			while (scanf("%d", &item), item != -1)
				SeqListPushBack(&mylist, item);
			break;
		case 2:
			printf("���������ݣ���-1������>");
			while (scanf("%d", item), item != -1)
				SeqListPushFront(&mylist, item);
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("��Ϊ��>%d\n", SeqListLength(&mylist));
			break;
		case 7:
			printf("������Ϊ��>%d\n", SeqListCapacity(&mylist));
			break;
		case 8:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SeqListDeleteByVal(&mylist, key);
			break;
		case 11:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if (pos == -1)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d���±�Ϊ%d��λ��.\n", key, pos);
			break;
		case 13:
			SeqListSort(&mylist);
			break;
		case 14:
			SeqListReverse(&mylist);
			break;
		case 15:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SeqListRemoveAll(&mylist, key);
			break;

		case 16:
			SeqListClear(&mylist);
			break;

		case 18:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			pos = SeqListFindByBinary(&mylist, key);
			if (pos == -1)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d���±�Ϊ%d��λ��.\n", key, pos);
			break;





		}
		system("pause");
		system("cls");
	}

	SeqListDestroy(&mylist);
	return 0;
}