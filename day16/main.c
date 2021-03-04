
#include "Heap.h"

int main()
{


	Heap hp;
	HeapElemType ar[] = { 27, 15, 19, 18, 34, 65, 49, 25, 37 };
	int n = sizeof(ar) / sizeof(ar[0]);
	HeapInitByArray(&hp, ar, n);
	/*HeapInit(&hp, 20);


	for (int i = 0; i < n; ++i)
		HeapInsert(&hp, ar[i]);

	//HeapShow(&hp);*/

	while (!HeapEmpty(&hp))
	{
		HeapElemType top_val = HeapTop(&hp);
		printf("%d ", top_val);
		HeapRemove(&hp);
	}
	printf("\n");

	system("pause");
	return 0;

}