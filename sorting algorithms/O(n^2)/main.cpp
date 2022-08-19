#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
/**
 * BUBBLE SORT – FLAGGED VERSION
 A flagged-version of The algorithm terminates
The checking if no swap were performed in a pass
 This improves The best-case running time to O(n)
(an almost sorted list)
 BUT The worst-case will still be O(n2
)
 */
void bubbleSort(int arr[], const int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void betterBubbleSort(int arr[], const int size)
// time complexity O(n^2)
// space Complexity O(1)
{
    bool flag = false;
    for (int i = 0; i < size - 1; i++)
    {
        flag = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (flag = false)
            break;
    }
}

int findMinIdx(const int arr[], const int size)
{

    int min = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[min])
            min = i;
    }
    return min;
}

void selectionSort(int arr[], const int size)
//   Time Complexity = O(n^2)
//   Space Complexity = O(1)
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
//   Time Complexity = O(n^2)
//   space complexity = O(1)
{
    int key, prev;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        prev = i - 1;

        while (prev >= 0 && arr[prev] > key)
        {
            arr[prev + 1] = arr[prev];
            prev = prev - 1;
        }
        arr[prev + 1] = key;
    }
}

void print(const int arr[], const int size)
{
    cout << "The array is " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void printSpace()
{
    cout << endl
         << endl
         << endl
         << "--------------------------------------------------------------------------" << endl;
}

int main()
{

    printSpace();

    int bubbleArr[10];

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        bubbleArr[i] = rand() % 100;
    }

    int bubbleSize = sizeof(bubbleArr) / sizeof(bubbleArr[0]);
    print(bubbleArr, bubbleSize);
    cout << "The min elelemnt is at index " << findMinIdx(bubbleArr, bubbleSize) << endl;
    // bubbleSort(bubbleArr, bubbleSize);
    betterBubbleSort(bubbleArr, bubbleSize);
    cout << "bubble sorting.... " << endl;
    print(bubbleArr, bubbleSize);
    cout << "The min elelemnt is at index " << findMinIdx(bubbleArr, bubbleSize) << endl;

    printSpace();

    int selectionArr[10];

    for (int i = 0; i < 10; i++)
    {
        selectionArr[i] = rand() % 100;
    }

    int selectionSize = sizeof(selectionArr) / sizeof(selectionArr[0]);
    print(selectionArr, selectionSize);
    cout << "The min elelemnt is at index " << findMinIdx(selectionArr, selectionSize) << endl;

    selectionSort(selectionArr, selectionSize);
    cout << "selection sorting.... " << endl;
    print(selectionArr, selectionSize);
    cout << "The min elelemnt is at index " << findMinIdx(selectionArr, selectionSize) << endl;

    printSpace();

    int insertionArr[10];

    for (int i = 0; i < 10; i++)
    {
        insertionArr[i] = rand() % 100;
    }

    int insertionSize = sizeof(insertionArr) / sizeof(insertionArr[0]);
    print(insertionArr, insertionSize);
    cout << "The min elelemnt is at index " << findMinIdx(insertionArr, insertionSize) << endl;

    insertionSort(insertionArr, insertionSize);
    cout << "insertion sorting.... " << endl;
    print(insertionArr, insertionSize);
    cout << "The min elelemnt is at index " << findMinIdx(insertionArr, insertionSize) << endl;

    return 0;
}