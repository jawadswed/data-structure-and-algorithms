#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void print (vector<int> nums)
{
  cout<<"[ ";
  for (int i = 0; i< nums.size(); i++)
    {
      cout<<nums[i]<<"  ";
    }
  cout<<" ]"<<endl;
}

 void rotate(vector<int>& nums, int k) 
{
      
        for (int x = 0; x< k; x++)
        {
            cout<<"rotating for the "<<x+1<<" times"<<endl;
            int temp = nums[nums.size()-1];
            for (int i = nums.size()-1; i> 0; i--)
            {
                
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
            print(nums);
        }
}

void betterRotate(vector<int>& nums, int k) 
{
      vector<int> temp(nums.size());
      for(int i=0;i<nums.size();i++)
      {
        temp[(i+k)%nums.size()] = nums[i];
      }
  print(temp);
  cout<<endl;
}




  

int main() {

    vector<int> nums{1,2,3,1};
  vector<int> nums1{1,2,3,4};
  
  
  betterRotate(nums,3);
  rotate(nums,3);


  

  
  return 0;
}

