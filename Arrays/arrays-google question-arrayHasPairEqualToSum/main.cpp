#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

/* Problem - given an ORDERED integer array return the pair of numbers whose sum
add to some number k if not found return false.
input array = [1,2,3,9], sum = 8
output false, false
input array = [1,2,4,4], sum = 8
output 4, 4
Note: we cannot have pairs of same index numbers.
*/

bool sumOfPair(const int arr[], const int sum, const int arrSize){

  for (int i = 0; i<arrSize; i++)
    {
      for (int j = i+1; j< arrSize; j++)
        {
          if (arr[i] + arr[j] == sum)
            return true;
        }
    }
  return false;
}

bool betterSumOfPair(const int arr[], const int sum, const int arrSize)
{
  int low = 0;
  int high = arrSize -1;

  while (low < high)
    {
      if (arr[low] + arr[high] == sum)
        return true;
      else if (arr[low] + arr[high] > sum)
        high--;
      else
        low++;
    }

  return false;
}

void sortArray (int arr[], int size)
{
  int temp =0;
  for (int i = 0; i<size; i++)
    {
      for (int j = i+1; j< size; j++)
        {
          if (arr[i] > arr[j])
          {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
          }
        }
    }
}
void printArray (const int arr[], const int size)
  {
    for (int i = 0; i< size; i++)
      {
        cout<<arr[i]<< " ,";
      }
    cout<<endl;
  }

bool unsortedSumOfPair(int arr[], const int sum, const int arrSize)
{
  sortArray(arr,arrSize);
  bool ans = betterSumOfPair(arr, sum, arrSize);
  return ans;
}

bool betterUnsortedSumOfPair(int arr[], const int sum, const int arrSize)
{
  unordered_set<int>comp;
  for (int i = 0; i < arrSize; i++)
    {
      
      if (comp.find(arr[i]) != comp.end())
      {
        return true;
      }
      comp.insert(sum - arr[i]);
    }
  return false;
}
int main() {

  int arr1[] = {1,2,3,9};
  int arr2[] = {1,2,4,4};

  int arr3[] = {5,2,4,5,1,4,8,4,3,9,6,4,32,7,9,4,3};

  int size1 = sizeof(arr1)/sizeof(arr1[0]);
  int size2 = sizeof(arr2)/sizeof(arr2[0]);
  int size3 = sizeof(arr3)/sizeof(arr3[0]); 
  int sum = 80;
  
  bool ans = betterSumOfPair(arr1, sum, size1);

  if (ans)
    cout<<"true";
  else
    cout<<"false";

cout<<endl<<"before sorting the array " <<endl;
  printArray(arr3,size3);
cout<<"after sorting the array "<<endl;
  sortArray(arr3,size3);
  printArray(arr3,size3);
    
  cout<<"using unsorted array "<<endl;
  bool ans2 = betterUnsortedSumOfPair(arr3, sum, size3);
    if (ans2)
    cout<<"true";
  else
    cout<<"false";

  

  return 0;
}

