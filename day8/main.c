#include"SeqList.h"

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
		printf("请选择：>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入数据，以-1结束：>");
			while (scanf("%d", item), item != -1)
				SeqListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入数据，以-1结束：>");
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

		}

	}


	//system("pause");
	return 0;
}