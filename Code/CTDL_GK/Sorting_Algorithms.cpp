#include"Sorting_Algorithms.h"
#include "Data_Generator.h"
#include <algorithm>


void printArray(int a[], int n)// in các phần tử của mảng
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void selectionSort(int a[], int n)
{
    int min;
    // One by one move boundary of unsorted subarray  
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array  
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        // Swap the found minimum element with the first element  
        swap(a[min], a[i]);
    }
}

int min(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}


void merge_helper(int* a, int left, int right, int* scratch)
{
    /* base case: one element */
    if (right == left + 1)
    {
        return;
    }
    else
    {
        int i = 0;
        int length = right - left;
        int midpoint_distance = length / 2;
        /* l and r are to the positions in the left and right subarrays */
        int l = left, r = left + midpoint_distance;

        /* sort each subarray */
        merge_helper(a, left, left + midpoint_distance, scratch);
        merge_helper(a, left + midpoint_distance, right, scratch);

        /* merge the arrays together using scratch for temporary storage */
        for (i = 0; i < length; i++)
        {
 
            if (l < left + midpoint_distance &&
                (r == right || min(a[l], a[r]) == a[l]))
            {
                scratch[i] = a[l];
                l++;
            }
            else
            {
                scratch[i] = a[r];
                r++;
            }
        }
        /* Copy the sorted subarray back to the input */
        for (i = left; i < right; i++)
        {
            a[i] = scratch[i - left];
        }
    }
}


void mergeSort(int* a, int size)
{
    int* scratch = new int[size];
    if (scratch != NULL)
    {
        merge_helper(a, 0, size, scratch);
        delete[] scratch;
        return ;
    }
    else
    {
        return ;
    }
}


void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//QUICK SORT

void quick_Sort(int a[], int left, int right) {
    int i, j;
    int pivot = a[(left + right) / 2];
    i = left; j = right;
    do
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (left < j)
        quick_Sort(a, left, j);
    if (i < right)
        quick_Sort(a, i, right);
}

void quickSort(int a[], int n)
{
    quick_Sort(a, 0, n - 1);
}
//BUBBLE SORT
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int binarySearch(int arr[], int item, int low, int high)
{
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);

    return binarySearch(arr, item, low, mid - 1);
}

void binaryinsertionSort(int arr[], int n)
{
    int i, j, k, selected, location;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        selected = arr[i];

        // location to insert
        location = binarySearch(arr, selected, 0, j);

        while (j >= location)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}
