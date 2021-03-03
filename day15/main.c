#include"Tree.h"


void main()
{
	char *vlr = "ABCDEFGH";
	char *lvr = "CBEDFAGH";
	char *lrv = "CEFDBHGA";
	BinTree bt;
	BinTreeInit(&bt);
	int n = strlen(vlr);
	//bt = BinTreeCreate_VLR_LVR(vlr, lvr, n);
	bt = BinTreeCreate_LVR_LRV(lvr, lrv, n);
	//BinTreeDestroy(&bt);



	/*char *str = "ABC##DE##F##G#H##";
	BinTree bt;
	BinTreeInit(&bt);

	//BinTreeCreate_1(&bt);
	//bt = BinTreeCreate_2();
	int index = 0;
	bt = BinTreeCreate_3(str, &index);
	printf("VLR : ");
	//PreOrder(bt);
	PreOrder_Nor(bt);
	printf("\n");
	printf("LVR : ");
	//InOrder(bt);
	InOrder_Nor(bt);
	printf("\n");
	printf("LRV : ");
	//PostOrder(bt);
	PostOrder_Nor(bt);
	printf("\n");
	printf("Level : ");
	LevelOrder(bt);
	printf("\n");
	printf("Size = %d\n", Size(bt));   //8
	printf("Height = %d\n", Height(bt));   //
	char key = 'A';
	BinTreeNode *p = Find(bt, key);
	BinTreeNode *pr = Parent(bt, p);
	BinTree bt1 = Clone(bt);
	bool flag = Equal(bt, bt1);*/


	system("pause");
	return 0;

}