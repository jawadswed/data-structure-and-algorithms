#include <iostream>
using namespace std;
 
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
 
int main()
{
 
    int arr[] = { 9, 3, 4, 2, 1, 8 };
    int n = 6;
 
    quickSort(arr, 0, n - 1);
 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
 
    return 0;
}


/**
                                                                          // Code for quick sort
#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int *a, int *b)                                               // Function for swapping the array elements                          
        {
            int temp;
            temp = *a;
            *a = *b;
            *b = temp;
        }

int Partition(int a[], int lowerIndex, int upperIndex)                   // Partitioning of the array
        {
            int pivot, index, i;
            index = lowerIndex;
            pivot = upperIndex;
            for (i = lowerIndex; i < upperIndex; i++)
            {
                    if (a[i] < a[pivot])
                    {
                        swap(&a[i], &a[index]);
                        index++;
                    }
            }
            swap(&a[pivot], &a[index]);
            return index;
    }

int QuickSort(int a[], int lowerIndex, int upperIndex)              
    {
            int pindex;
            if (lowerIndex < upperIndex)
            {
                pindex = Partition(a, lowerIndex, upperIndex);
                QuickSort(a, lowerIndex, pindex - 1);                             // Recursively calling function
                QuickSort(a, pindex + 1, upperIndex);
            }
            return 0;
    }
int main()
    {
        int n, i;
      cout << "\nEnter the number of data elements to be sorted: ";            // Taking size of array as input
      cin >> n;
        int arr[n];
            for (i = 0; i < n; i++)
                {
                    cout << "Enter elements " << i + 1 << ": ";
                    cin >> arr[i];
                }
        QuickSort(arr, 0, n - 1);
        cout << "\nSorted Data ";
        for (i = 0; i < n; i++)
            cout << " " << arr[i];
        return 0;
    }
 */