#include <iostream>
#include <bits/stdc++.h>

using namespace std;

 void moveZeroes(vector<int>& nums) { 
            
     int i = 0;
        for(int j = 0; j<nums.size(); j++)
        {
            if(nums[j] != 0)
            {
                swap(nums[i],nums[j]);
                i++;
            }
        }
        
        
    }

  

int main() {

    vector<int> nums{0,1,0,3,12};
  vector<int> nums1{0};

  

  for (int i = 0; i< nums.size(); i++)
    {
      cout<< nums[i]<< " ";
    }
  cout<<endl;

  cout<< "after moving the zeroes "<<endl;
  moveZeroes(nums);
   for (int i = 0; i< nums.size(); i++)
    {
      cout<< nums[i]<< " ";
    }
  cout<<endl;
  
  return 0;
}

