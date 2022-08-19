// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
        indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Driver code
int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1, 1, 54, 3, 23, 5, 6, 32, 23, 5, 6, 554, 435, 6, 43, 2, 34, 5, 6, 4, 3, 234, 4};
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    int arr4[] = {1, 5, 3, 5, 6, 2, 1, 2, 58, 4, 2, 4, 6, 8, 54, 3, 2, 34, 6, 7, 53};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "\nGiven array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);

    cout << "\nGiven array is \n";
    printArray(arr4, size4);

    mergeSort(arr4, 0, size4 - 1);

    cout << "\nSorted array is \n";
    printArray(arr4, size4);
    return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes

// /* This program is based on the sorting algorithm called MergeSort
// This algorithm is based on the divide and concur approach
// Time complexity = O(n log n)
// Space Complexity = O(n)
// */
// #include <iostream>
// #include <cstdlib>
// using namespace std;

// void mergeArray(int arr[], int low, int mid, int high) {
//     int size1 = mid - low + 1;
//     int size2 = high - mid;

//     int leftArr[size1], rightArr[size2];

//     for(int i = 0; i < size1; i++) {
//         leftArr[i] = arr[low + i];
//     }
//     for(int j = 0; j < size2; j++) {
//         rightArr[j] = arr[mid + 1 + j];
//     }
//     int i = 0; // index traversing in leftArray
//     int j = 0; // index traversing in rightArray
//     int k = low; // index traversing in original Array

//     while(i < size1 && j < size2) {
//         if(leftArr[i] <= rightArr[j]) {
//             arr[k] = leftArr[i];
//             i++;
//         }
//         else {
//             arr[k] = rightArr[j];
//             j++;
//         }
//         k++;
//     }
//     // inserting remaining elements
//     while(i < size1) {
//         arr[k] = leftArr[i];
//         i++;
//         k++;
//     }
//     while(j < size2) {
//         arr[k] = rightArr[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(int arr[], int low, int high) {  // this function divides the array until it can't be divided into half

//     if(low < high) {
//         int mid = (low + (high - 1))/2;

//         mergeSort(arr, low, mid);
//         mergeSort(arr, mid + 1, high);

//         mergeArray(arr, low, mid, high);
//     }
// }

// int main() {
//     int arr[] = {10, 9, 8, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1, 1,54,3,23,5,6,32,23,5,6,554,435,6,43,2,34,5,6,4,3,234,4};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     mergeSort(arr, 0, n);

//     cout<<"Sorted Array is: "<<endl;
//     for(int i = 0; i < n; i++) {
//         cout<<arr[i]<<"  ";
//     }

//     return 0;
// }