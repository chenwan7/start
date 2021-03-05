#include"Sort.h"


int main()
{
	//int ar[] = {49, 38, 65, 97, 76, 13, 27, 49};
	//int ar[] = {12, 38, 65, 97, 100, 200, 300};
	//int ar[] = {9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
	//int ar[] = {10, 6, 7, 1, 3, 9, 4, 2};
	int ar[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintArray(ar, 0, n);

	//≈≈–Ú
	//InsertSort_1(ar, 0, n);
	//InsertSort_2(ar, 0, n);
	//InsertSort_3(ar, 3, 6);
	//BinInsertSort(ar, 0, n);
	//TwoWayInsertSort(ar, 0, n);
	//ShellSort(ar, 0, n);
	//SelectSort(ar, 0, n);
	//HeapSort(ar, 3, 6);

	//BubbleSort_1(ar, 0, n);
	//BubbleSort_2(ar, 0, n);
	//QuickSort(ar, 0, n);
	//MergeSort(ar, 0, n);
	RadixSort(ar, 0, n);


	PrintArray(ar, 0, n);

	//≤‚ ‘–ß¬ 
	TestSortEfficient();
	system("pause");
	return 0;

}


