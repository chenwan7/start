#include"List.h"
#pragma warning (disable: 4996)


int main()

{
	//List mylist;      //链表
	////  ListNode *mylist  //节点的指针
	//ListInit(&mylist);
	//ListCreate(&mylist);
	////ListCreate_Head(&mylist);
	//ListCreate_Tail(&mylist);
	//ListShow(mylist);

	//SList mylist;
	//SListInt(&mylist);

	DCList mylist;
	DCListInit(&mylist);
	ElemType item, key;
	int pos;

	//SListNode *p;

	DCListNode *p;

	int select = 1;
	while (select)
	{
		printf("**********************************\n");
		printf("*[1]pushback       [2]pushfront  *\n");
		printf("*[3]showlist       [4]popback    *\n");
		printf("*[5]popfront       [6]length     *\n");
		printf("*[*7]capacity      [8]insertval  *\n");
		printf("*[*9]insertpos     [10]deleteval *\n");
		printf("*[*11]deletepos    [12]find      *\n");
		printf("*[13]sort          [14]reverse   *\n");
		printf("*[15]removeall     [16]clear     *\n");
		printf("*[17]destroy       [*18]findbinary*\n");
		printf("*[0]quitsystem                   *\n");
		printf("**********************************\n");
		printf("请选择：>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入数据，以-1结束：>");
			while (scanf("%d", &item), item != -1)
				DCListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入数据，以-1结束：>");
			while (scanf("%d", item), item != -1)
				DCListPushFront(&mylist, item);
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			printf("表长为：>%d\n", DCListLength(&mylist));
			break;
		case 7:
			//printf("表容量为：>%d\n", SeqListCapacity(&mylist));
			break;
		case 8:
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			DCListDeleteByVal(&mylist, key);
			break;
		case 11:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if (pos == NULL)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d存在.\n", key);
			break;
		case 13:
			//SListSort(&mylist);
			break;
		case 14:
			DCListReverse(&mylist);
			break;
		case 15:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			//SListRemoveAll(&mylist, key);
			break;

		case 16:
			DCListClear(&mylist);
			break;

		case 18:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			//pos = SeqListFindByBinary(&mylist, key);
			if (pos == -1)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d在下标为%d的位置.\n", key, pos);
			break;





		}
		system("pause");
		system("cls");
	}

	DCListDestroy(&mylist);
	return 0;
}


