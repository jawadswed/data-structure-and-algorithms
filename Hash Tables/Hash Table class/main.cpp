#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int TABLE_SIZE = 128;

class HashTable {
public:
int key;
int value;

HashTable(int key, int value)
{
  this->key = key;
  this->value = value;
}

};

class HashMap {
private:
HashTable **table;
public:
HashMap ()
{
  table = new HashTable * [TABLE_SIZE];
  for (int i = 0; i< TABLE_SIZE; i++)
    {
      table[i] = NULL;
    }
}

int HashFunction (int key) 
{
  return key % TABLE_SIZE;
}

void insertElement (int key, int value)
{
  int h = HashFunction(key);

  while (table[h] != NULL && table[h]->key != key)
    {
      h = HashFunction(h+1);
    }
  
  if (table[h] != NULL)
    delete table[h];

  table[h] =  new HashTable (key, value);
}

int searchElement(int key)
{
  int h = HashFunction(key);

  while(table[h] != NULL && table[h]->key != key)
    {
      h = HashFunction(h+1);
    }

  if (table[h] == NULL)
    return -1;
  else
    return table[h]->value;
}

void removeElement(int key)
{
  int h = HashFunction(key);
  while (table[h] != NULL)
    {
      if (table[h]->key == key)
        break;
      h = HashFunction(h+1);
    }
  if (table[h] == NULL)
  {
    cout<<"no element was found at key "<< key<< endl;
    return;
  }
  else
  {
    delete table[h];
  }
  cout<<"element was deleted"<<endl;
}

~HashMap()
{
  for (int i = 0; i < TABLE_SIZE; i++)
    {
      if (table[i] !=NULL)
        delete table[i];
      delete[] table;
    }
}
};


  

int main() {


HashMap hash;
   int k, v;
   int c;
   while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>v;
            cout<<"Enter key at which element to be inserted: ";
            cin>>k;
            hash.insertElement(k, v);
         break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            if (hash.searchElement(k) == -1) {
               cout<<"No element found at key "<<k<<endl;
               continue;
            } else {
               cout<<"Element at key "<<k<<" : ";
               cout<<hash.searchElement(k)<<endl;
            }
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>k;
            hash.removeElement(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"Enter correct option";
      }
   }
  
  return 0;
}

