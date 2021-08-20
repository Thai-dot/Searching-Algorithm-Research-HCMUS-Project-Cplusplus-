#include "Data_Generator.h"
#include "Sorting_Algorithms.h"

int main()
{
	int select = -1;
	int number = -1;
	clock_t start, end;
	int* a;
	double time_use;

	cout << "Nhap kieu ban muon de tao mang" << endl;
	cin >> select;
	cout << "Nhap so luong phan tu mang: " << endl;
	cin >> number;
	cout << "Phan tu mang la: " << number << endl;
	
	//Selection Sort
	a = new int[number];
	GenerateData(a, number, select);
	cout << "********   Truong hop du lieu gan nhu co thu tu  ********" << endl;
	cout << endl;
	cout << "Thoi gian chay cua selection sort: ";
	start = clock();
	
	selectionSort(a, number);

	end = clock();
	
	time_use = (double)(end - start) / CLOCKS_PER_SEC;

	cout << time_use << "s"<< endl;
	time_use = 0;
	delete[] a;
	//Merge Sort
	a = new int[number];
	GenerateData(a, number, select);
	cout << "Thoi gian chay cua merge sort: ";
	start = clock();

	mergeSort(a, number);

	end = clock();

	time_use = (double)(end - start) / CLOCKS_PER_SEC;

	cout << time_use <<"s"<< endl;
	time_use = 0;
	delete[] a;
	//Heap Sort
	a = new int[number];
	GenerateData(a, number, select);
	cout << "Thoi gian chay cua heap sort: ";
	start = clock();

	heapSort(a, number);

	end = clock();

	time_use = (double)(end - start) / CLOCKS_PER_SEC;

	cout << time_use << "s" << endl;
	time_use = 0;
	delete[] a;
	//Quick Sort
	a = new int[number];
	GenerateData(a, number, select);
	cout << "Thoi gian chay cua quick sort: ";
	start = clock();

	quickSort(a, number);

	end = clock();

	time_use = (double)(end - start) / CLOCKS_PER_SEC;

	cout << time_use << "s" << endl;
	time_use = 0;
	delete[] a;

	//Bubble Sort
	a = new int[number];
	GenerateData(a, number, select);
	cout << "Thoi gian chay cua bubble sort: ";
	start = clock();

	bubbleSort(a, number);

	end = clock();

	time_use = (double)(end - start) / CLOCKS_PER_SEC;

	cout << time_use << "s" << endl;
	time_use = 0;
	delete[] a;
	//Insertion Sort
	a = new int[number];
	GenerateData(a, number, select);
	cout << "Thoi gian chay cua insertion sort: ";
	start = clock();

	insertionSort(a, number);

	end = clock();

	time_use = (double)(end - start) / CLOCKS_PER_SEC;

	cout << time_use << "s" << endl;
	time_use = 0;
	delete[] a;
	//Binary Insertion Sort
	a = new int[number];
	GenerateData(a, number, select);
	cout << "Thoi gian chay cua binary insertion sort: ";
	start = clock();

	binaryinsertionSort(a, number);

	end = clock();

	time_use = (double)(end - start) / CLOCKS_PER_SEC;

	cout << time_use << "s" << endl;
	time_use = 0;
	delete[] a;

	return 0;
}