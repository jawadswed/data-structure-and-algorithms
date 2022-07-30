#include <iostream>
#include <bits/stdc++.h>

using namespace std;

 int maxSubArray(vector<int>& nums) 
{
  if (nums.size() == 0)
    return 0;
        
  int maxSum = nums[0];
  for (int i = 0; i< nums.size(); i++)
  {
    int sum = 0;
    for (int j = i; j<nums.size(); j++)
    {
      sum += nums[j];
      maxSum = max(sum, maxSum);
    }
  }
  return maxSum;
        
}

int betterMaxSubArray(vector<int>& nums)
{
  if (nums.size() == 0)
    return 0;
  int sum = nums[0];
  int maxSum = nums[0];

  for (int i = 1; i< nums.size(); i++)
    {
      sum = max(sum + nums[i] , nums[i]);
      maxSum = max(maxSum, sum);
    }

  return maxSum;
}



  

int main() {

    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
  vector<int> nums1{};
  vector<int> nums2{5,4,-1,7,8};

  int sum = betterMaxSubArray(nums);
int sum1 = betterMaxSubArray(nums1);
  int sum2 = betterMaxSubArray(nums2);
  cout<<sum<<" "<<sum1<<" "<<sum2;
  
  return 0;
}

