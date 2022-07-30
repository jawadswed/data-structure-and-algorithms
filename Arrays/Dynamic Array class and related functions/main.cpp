#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

// push (int data) insert an element at the end ofthe array
// replace (int data, int index) replace the data at index position with new data
// insertElement (int data, int index) inserting element at index position
// pop() return the last element 
// pop(int index) delete the element at the index position
// get(int index) return the data at index postion
// length () return the length of the array
// print() print the array
// sort() sort the array
// sort(int index) sort the array from that index forward 
class MyArray {

int *arr;
int capacity;
int totalElement;

public:
MyArray ()
{
  arr = new int [2];
  capacity = 2;
  totalElement = 0;
}

void push(int data) {
if (totalElement == capacity) // if the array we have i filled
{
  int *temp = new int [capacity *2]; // define a new pointer with double the capacity 

  for (int i = 0; i< capacity; i++)
    {
      temp[i] = arr[i]; // copy all the elements form array to the new array pointer temp
    }
  delete [] arr; // delete the memory allocated by pinter arr
  capacity = capacity *2; // increase the capacity to match the capacity of temp
  arr = temp; // point arr to temp;
}
  arr[totalElement] = data; // we insert the element at the end of the array
  totalElement++; // increase the number of element by 1 
}

void replace(int data, int index)
{
  arr[index] = data;
  
}

void insertElement(int data, int index)
{
  if (index == capacity)
  {
    push(data);
  }
  else
  {
    for (int i = totalElement; i> index; i--)
      {
        arr[i] = arr[i-1];
      }
    arr[index] = data;
    totalElement++;
  }
}

int pop()
{
  int x = arr[totalElement-1];
  totalElement--;
  return x;
}

void pop (int index)
{
  if (index > -1 && index < totalElement)
  {
    totalElement--;
    for (int i = index; i< totalElement; i++)
      {
        arr[i] = arr[i+1];
      }
  }
}

int get(int index)
{
  if (index>-1 && index < totalElement)
    return arr[index];
  else return -1;
}

int length ()
{
  return totalElement;
}

void print()
{
  for (int i=0; i<totalElement;i++)
    {
      cout<< arr[i]<< " ";
    }
  cout<<endl;
}

void sortBtS()
{
  for (int i = 0 ; i < totalElement; i++)
    {
      for (int j = i+1; j < totalElement; j++ )
        {
          if (arr[i] < arr[j])
          {
            int temp = arr[i];
            arr[i]= arr[j];
            arr[j] = temp;
          }
        }
    }
}

void sortStB()
{
  for (int i =0 ;i<totalElement;i++)
    {
      for (int j = i+1; j<totalElement;j++)
        {
          if (arr[i] > arr[j])
          {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] =temp;
          }
        }
    }
}

void sort(int index)
{
   for (int i = index ; i < totalElement; i++)
    {
      for (int j = index+1; j < totalElement; j++ )
        {
          if (arr[i] > arr[j])
          {
            int temp = arr[i];
            arr[i]= arr[j];
            arr[j] = temp;
          }
        }
    }
}

void initializeArray (int size)
{
  for (int i = 0 ; i< size; i++)
    {
      push(rand()%100); 
    }
}

void mergeAtBeg(int arr1[], int size)
{
  for (int i = 0; i< size; i++)
    {
      insertElement(arr1[i], i);
    }
}

void mergeAtEnd(int arr1[], int size)
{
  for (int i=0; i < size;i++)
    {
      insertElement(arr1[i],totalElement);
    }
}
  
};

int main() {

  // push (int data) insert an element at the end ofthe array
// replace (int data, int index) replace the data at index position with new data
// insertElement (int data, int index) inserting element at index position
// pop() return the last element 
// pop(int index) delete the element at the index position
// get(int index) return the data at index postion
// length () return the length of the array
// print() print the array
// sort() sort the array
// sort(int index) sort the array from that index forward 
  
  MyArray arr;

  int arr1 [] = {1,2,3,4,5}; 
  arr.initializeArray(10);

  arr.print();
   arr.push(10);
  arr.print();
  arr.replace(11, 0);
  arr.print();
  arr.replace(11,arr.length()-1);
  arr.print();
  arr.insertElement(88,1);
  arr.print();
  arr.pop();
  arr.print();
  arr.pop(0);
  arr.print();
  int i = arr.get(0);
  cout<<i<<endl;
  int j = arr.length();
  cout<<j<<endl;
  arr.sortBtS();
  arr.print();
  arr.sortStB();
  arr.print();

  arr.mergeAtEnd(arr1,5);
  arr.print();
   arr.sortBtS();
  arr.print();
  arr.sortStB();
  arr.print();

  return 0;
}

