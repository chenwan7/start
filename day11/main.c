#include"List.h"
#pragma warning (disable: 4996)


int main()

{

	SList mylist;
	SListInt(&mylist);

	ElemType item, key;
	int pos;

	SListNode *p;

	int select = 1;
	while (select)
	{
		printf("**********************************\n");
		printf("*[1]pushback       [2]pushfront  *\n");
		printf("*[3]showlist       [4]popback    *\n");
		printf("*[5]popfront       [6]length     *\n");
		printf("*[7]insertval      [8]deleteva   *\n");
		printf("*[9]find           [10]sort      *\n");
		printf("*[11]reverse       [12]removeall *\n");
		printf("*[13]clear         [14]destroy   *\n");
		printf("*[0]quitsystem                   *\n");
		printf("**********************************\n");
		printf("��ѡ��>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("���������ݣ���-1������>");
			while (scanf("%d", &item), item != -1)
				SListPushBack(&mylist, item);
			break;
		case 2:
			printf("���������ݣ���-1������>");
			while (scanf("%d", item), item != -1)
				SListPushFront(&mylist, item);
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("��Ϊ��>%d\n", SListLength(&mylist));
			break;
		case 7:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			break;			
		case 9:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = SListFind(&mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d����.\n", key);
			break;
		case 10:
			SListSort(&mylist);
			break;
		case 11:
			SListReverse(&mylist);
			break;
		case 12:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SListRemoveAll(&mylist, key);
			break;

		case 13:
			SListClear(&mylist);
			break;
		case 14:
			SListDestroy(&mylist);


		}
		system("pause");
		system("cls");
	}

	SListDestroy(&mylist);
	return 0;
}


