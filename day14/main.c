#include"Queue.h"

void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q, 0);
	SeqQueueEn(&Q, 1);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 5);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 2);
	SeqQueueEn(&Q, 6);
	SeqQueueEn(&Q, 7);
	SeqQueueEn(&Q, 8);
	SeqQueueEn(&Q, 20);
	SeqQueueDe(&Q);
	SeqQueueEn(&Q, 20);
	SeqQueueDe(&Q);
	SeqQueueEn(&Q, 30);
	SeqQueueShow(&Q);





	/*SeqQueue Q;
	SeqQueueInit(&Q, 0);
	SeqQueueEn(&Q, 1);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 5);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 2);
	SeqQueueShow(&Q);
	printf("====================\n");
	SeqQueueDe(&Q);
	SeqQueueShow(&Q);
	int val = SeqQueueBack(&Q);
	printf("back val = %d\n", val);
	val = SeqQueueFront(&Q);
	printf("front val = %d\n", val);
	SeqQueueEn(&Q, 100);
	val = SeqQueueBack(&Q);
	printf("back val = %d\n", val);
	val = SeqQueueFront(&Q);
	printf("front val = %d\n", val);*/







	/*LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEn(&Q, 1);
	LinkQueueEn(&Q, 2);
	LinkQueueEn(&Q, 3);
	LinkQueueEn(&Q, 4);
	LinkQueueEn(&Q, 15);
	LinkQueueEn(&Q, 6);
	LinkQueueShow(&Q);
	printf("==============\n");

	QueueElemType val1 = LinkQueueFront(&Q);
	LinkQueueDe(&Q);
	printf("%d 出队.\n", val1);
	LinkQueueShow(&Q);
	QueueElemType val2 = LinkQueueFront(&Q);
	LinkQueueDe(&Q);
	printf("%d 出队.\n", val2);
	LinkQueueShow(&Q);
	LinkQueueDestroy(&Q);*/



	system("pause");


}









/*#include"Stack.h"

void main()
{





	LinkStack st;
	LinkStackInit(&st);
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 5);
	LinkStackShow(&st);
	printf("============\n");
	StackElemType val = LinkStackTop(&st);
	LinkStackPop(&st);
	LinkStackShow(&st);
	printf("%d 出栈.\n", val);
	LinkStackDestroy(&st);


	system("pause");


}*/

//void main()
//{
//	SeqStack st;
//	SeqStackInit(&st, 0);
//	SeqStackPush(&st, 1);
//	SeqStackPush(&st, 2);
//	SeqStackPush(&st, 3);
//	SeqStackPush(&st, 4);
//	SeqStackPush(&st, 5);
//	SeqStackShow(&st);
//	printf("============\n");
//	while (!IsEmpty(&st))
//	{
//		StackElemType val = SeqStackTop(&st);
//		SeqStackPop(&st);
//		printf("%d 出栈.\n", val);
//	}
//	printf("出栈完毕.\n");
//	SeqStackDestroy(&st);
//}
