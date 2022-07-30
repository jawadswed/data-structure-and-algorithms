#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
        
        bool found = false;
        
        for (int i = 0; i< nums.size(); i++)
        {
            for (int j = i+1 ; j < nums.size();j++)
            {
                if (nums[i] == nums[j])
                {
                   found = true;
                    break;
                }
                    
                
            }
        }
        
        return found;
        
    }

  bool betterContainsDuplicate(vector<int>& nums) {
        
        bool found = false;
        unordered_set <int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
            {
                found = true;
                break;
            }
            
            s.insert(nums[i]);
        }
        
        return found;
        
    }

  

int main() {

    vector<int> nums{1,2,3,1};
  vector<int> nums1{1,2,3,4};

  



  cout<< "after moving the zeroes "<<endl;
  bool ans = containsDuplicate(nums);
  bool ans1 = betterContainsDuplicate(nums1);

  cout<<ans<<" "<< ans1<<endl;
  
  return 0;
}

