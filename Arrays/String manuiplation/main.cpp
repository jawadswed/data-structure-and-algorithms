#include <iostream>
#include <bits/stdc++.h>


using namespace std;

void reverseString(string &s)
{
  int end = s.size()-1;
  int beg = 0;
   char c;
  while(beg <=end)
    {
      c= s[end];
      s[end]=s[beg];
      s[beg] = c;
      beg++;
      end--;
      
    }
}

void replaceLetter(string &s, char c, char r)
{
  if (s.size() == 0)
    cout<<"the string is empty"<<endl;
  else
  {
    bool found = false;
    for (int i = 0; i<s.size();i++)
      {
        if (s[i] == c)
        {
          found = true;
          s[i] = r;
        }
          
      }
    if (!found)
      cout<<"the letter you entered is not found"<<endl;
  }
}

int main() {

  string string1 = "jawad";

  
  cout<< string1<<endl;

  replaceLetter(string1, 'm','v');
  cout<< string1<<endl;

  reverseString(string1);
   cout<< string1<<endl;
  
 reverse(string1.begin(),string1.end());
   cout<< string1<<endl;

  int len = string1.length() -1;
  int i = 0;

  while(i<=len)
    {
      swap(string1[i], string1[len]);
      i++;
      len--;
        
    }

 
  
  cout<< string1<<endl;
  
  
  return 0;
}

