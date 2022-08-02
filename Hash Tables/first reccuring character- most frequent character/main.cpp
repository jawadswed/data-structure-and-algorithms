#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int firstRecurringCharacter(int arr[], int size)
{
  int x = 0;

  unordered_set<int> s;
  for (int i =0; i<size; i++)
    {
      if (s.find(arr[i]) != s.end())
      {
        x = arr[i];
        return x;
      }
      s.insert(arr[i]);
    }
  
  
  return x;
}

pair<int,int> numOfHighestOccurance(int arr[], int size)
{
  int element = -1;
  int max =0;
  pair< int, int> p;
  unordered_map <int,int> m;
  for (int i = 0; i< size;i++)
    {
      m[arr[i]]++;
    }
  for (auto i: m)
    {
      if (max < i.second)
      {
        element = i.first;
        max = i.second;
      }
    }
  p.first = element;
  p.second = max;

  return p;
  
}

int main() {

  int arr [] = {2,5,1,2,3,5,1,2,4,3,4,3,3,6,3,2,5};
  int arr2[] ={2,1,1,2,3,5,1,2,4};
  int arr3[] ={2,3,4,5};

  int size = sizeof(arr)/sizeof(arr[0]);
  int size2 = sizeof(arr2)/sizeof(arr2[0]);
  int size3 = sizeof(arr3)/sizeof(arr3[0]);

  int x = firstRecurringCharacter(arr,size);
  int x2 = firstRecurringCharacter(arr2,size2);
  int x3 = firstRecurringCharacter(arr3,size3);

  pair <int, int> p = numOfHighestOccurance(arr,size);

  cout<<"element is "<<p.first<< " and it occured "<< p.second<<" times"<<endl;

  cout<<" X is "<< x<<" X2 is "<<x2<<" X3 is "<<x3<<endl;

  return 0;
}

