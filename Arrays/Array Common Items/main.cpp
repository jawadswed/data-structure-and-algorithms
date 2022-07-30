#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool commonItem (const char arr1[],const char arr2[], const int size1, const int size2)
  {
    if(arr1 == NULL || arr2 == NULL)
      return false;
    


    for (int i = 0; i< size1; i++)
      {
        for (int j = 0; j< size2; j++)
          {
            if (arr1[i] == arr2[j])
              return true;
          }
      }
    return false;

    
  }
bool betterCommonItem (const char arr1[], const char arr2[], int size1, int size2){
  map<int,int> a;

  for (int i = 0; i< size1; i++)
    {
      if (a.find(arr1[i]) == a.end())
        a.insert({arr1[i], true});
    }

  for (int i = 0; i< size1; i++)
  {
    if (a.find(arr2[i]) != a.end())
      return true;
    
  }

  return false;
}

int main() {
char arr1 [] = {'a','b','c','x'};
char arr2 [] = {'z','y','i'};

char arr3 [] = {'a','b','c','x'};
char arr4 [] = {'z','y','x'};

    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
      int size3 = sizeof(arr3)/sizeof(arr3[0]);
    int size4 = sizeof(arr4)/sizeof(arr4[0]);
bool ans= commonItem(arr3, arr4, size3, size4);
  cout<< ans<<endl;
  cout<<"the first function answer is ";
  if (ans == true)
    cout<<"true";
  else
    cout<<"false";


  cout<<endl<<"the second function answer is ";
  bool ans2 = betterCommonItem(arr3, arr4,size3,size4);
   if (ans2 == true)
    cout<<"true";
  else
    cout<<"false";
         
    
    

  

  return 0;
}

