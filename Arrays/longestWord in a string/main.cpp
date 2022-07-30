#include <iostream>
#include <bits/stdc++.h>

using namespace std;


string LongestWord(string sen) {
  string longestWord;
  int count = 0; 
  int longest = 0;

  for (int i = 0; i <= sen.length(); i++)
  {
    if (isalpha(sen[i]) != 0)
    {
      count++;
    }
    else
    {
      if (count > longest)
      {
        longest = count;
        longestWord = sen.substr(i - longest, longest);
      }
      count = 0;
    }
  }
  
  return longestWord;

}


  

int main() {

  string s = "hey this is really fun!!  lets do it... again";


  string ans = LongestWord(s);
  cout << ans;

  
  return 0;
}

