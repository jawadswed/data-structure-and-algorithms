#include <iostream>
// #include <stack>
// #include <queue>
// #include "singleLL.cpp"
// #include "stackLL.cpp"
// #include "stackArray.cpp"
// #include "queueLL.cpp"
// #include "queueArray.cpp"
// #include "queueStack.cpp"

using namespace std;

int binerySearchElem(const int arr[], const int size, int data)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - 1) / 2;
        if (arr[mid] == data)
            return mid;
        if (arr[mid] < data)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << "element was not found " << endl;
    return -1;
}
int recBinerySearchElem(const int arr[], int beg, int end, int data)
{
    if (end < beg)
        return -1;
    int mid = (beg + end) / 2;
    if (arr[mid] == data)
        return mid;
    if (arr[mid] < data)
        return recBinerySearchElem(arr, mid + 1, end, data);
    if (arr[mid] > data)
        return recBinerySearchElem(arr, beg, mid - 1, data);
}

void bubbleSort(int arr[], const int size) // O(n^2)
{
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void betterBubbleSort(int arr[], const int size)
// best case (almost sorted) O(n) but worst case still an O(n^2)
// terminates the checking if no swap were performed in a pass
{
    bool swapDone = true;
    int j = 0;
    int temp = 0;

    while (swapDone && j < size - 1)
    {
        swapDone = false;

        for (int i = 0; i < size - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapDone = true;
            }
        }
        j++;
    }
}

void selectionSort(int arr[], int size) // o(n^2)
{
    int minIndex, temp;

    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int size) // O(n^2)
{
    int i, key, j;
    for (i = 1; i < size; i++)
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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9};

    int size = sizeof(arr) / sizeof(arr[0]);

    int arr1[] = {1, 5, 3, 5, 6, 2, 1, 2, 58, 4, 2, 4, 6, 8, 54, 3, 2, 34, 6, 7, 53};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int i = binerySearchElem(arr, size, 7);
    cout << i << endl;
    bubbleSort(arr1, size1);

    int arr2[] = {1, 5, 3, 5, 6, 2, 1, 2, 58, 4, 2, 4, 6, 8, 54, 3, 2, 34, 6, 7, 53};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    betterBubbleSort(arr2, size2);
    cout << "running buuble sort" << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << "  ";
    }
    cout << endl;
    cout << "running an improved buuble sort" << endl;
    for (int i = 0; i < size2; i++)
    {
        cout << arr2[i] << "  ";
    }
    cout << endl;
    int arr3[] = {1, 5, 3, 5, 6, 2, 1, 2, 58, 4, 2, 4, 6, 8, 54, 3, 2, 34, 6, 7, 53};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    selectionSort(arr3, size3);
    cout << "running the selection sort" << endl;
    for (int i = 0; i < size3; i++)
    {
        cout << arr3[i] << "  ";
    }
    cout << endl;
    int arr4[] = {1, 5, 3, 5, 6, 2, 1, 2, 58, 4, 2, 4, 6, 8, 54, 3, 2, 34, 6, 7, 53};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    insertionSort(arr4, size4);
    cout << "running the insertion sort" << endl;
    for (int i = 0; i < size4; i++)
    {
        cout << arr4[i] << "  ";
    }
    cout << endl;

    int rec = recBinerySearchElem(arr3, 0, size3 - 1, 1);

    cout << rec;

    return 0;
}