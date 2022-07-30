#include <iostream>
#include <bits/stdc++.h>

using namespace std;




int *mergeTwoSorted (int arr1[], int arr2[], int size1, int size2)
{
  if (size1 == 0)
    return arr2;
  if (size2 == 0)
    return arr1;
  
  int *arr = new int [size1 + size2]; 
  
  int index = 0;
  int index1 = 0;
  int index2= 0;
  
  while(index1 <size1 && index2< size2)
    {
      if(arr1[index1] <= arr2[index2])
      {
        arr[index] = arr1[index1];
        index1++;
      }
      else
      {
        arr[index] = arr2[index2];
        index2++;
      }
      index++;
    }

 
    for (int i = index2; i < size2; i++)
    {
      arr[index] = arr2[i];
      index++;
    }

    for (int i = index1; i < size1; i++)
    {
      arr[index] = arr1[i];
      index++;
    }
  
 
  
  return arr;
}
  

int main() {

    int arr1[] = {1,2,3,4,5,6,7};
    int arr2[] = {3,4,5,7,8,9,10,11};
    
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int *newArr = mergeTwoSorted(arr1, arr2, size1, size2);
    cout<<"Merged Array: "<<endl;
    for(int i = 0; i < size1+size2; i++) {
        cout<<newArr[i]<<"  ";
    }
    cout<<endl;
  
  return 0;
}

