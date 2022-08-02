#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
 Node () : data(0), nextLink(NULL), previousLink(NULL) {}
 Node (int theData, Node *previous, Node *next)
 : data(theData), nextLink(next), previousLink(previous) {}
 Node *getNext( ) const { return nextLink; }
 Node *getPrev( ) const { return previousLink; }
int getData( ) const { return data; }
 void setData(int theData) { data = theData; }
 void setNext(Node *pointer) { nextLink = pointer; }
 void setPrev(Node *pointer) { previousLink = pointer; }
// ~Node();
private:
 int data; //to simplify, we are using only one piece of data
 Node *nextLink;
 Node *previousLink;
};

class MyDoubleLinkedList {
public:
    Node* head;
    Node* tail;

 MyDoubleLinkedList() {
    head = NULL;
    tail = NULL;
}

int get(int index) {
    
  if(head == NULL ||index < 0) // if list is empty or index is less than 0
     return -1;
  if (index == 0) // if the index is the first element
    return head->getData();
  
  Node* curr = head;
  while(curr != NULL && index > 0) // other test cases
    {
      curr = curr->getNext();
      index--;
    }
  if (curr == NULL &&index==0) // if the index is bigger than list count
    return -1;
  return curr->getData();
}

void addAtHead(int val) {
    
Node* temp= new Node(val, NULL, head);
  if (head == NULL)
  {

    head = temp;
    tail = temp;
  }
  else
  {
    head->setPrev(temp);
    head = temp;
  }
  
}

void addAtTail(int val) {
     
  Node* temp = new Node(val, tail, NULL);
  if (head == NULL)
  {
     head = temp;
    tail = temp;
  }
  else
  {
    tail->setNext(temp);
    tail = temp;
  } 
  
}

bool search(int val) const
{
  if(head == NULL)
  {
    cerr<<"List is empty. "<<endl;
    return false;
  }
  else
  {
    bool found = false;
    Node* curr = head;
    while (curr != NULL && !found)
      {
        if (curr->getData() == val)
          found = true;
        else
          curr = curr->getNext();
      }
    return found;
  }
}

void addAtIndex(int index, int val) {
     
if (index < 0) // if index is less than 0
{
  cerr<<"not a valid index"<<endl;
}
  else if (index == 0 ) // if the element to be added at index 0
  {
    Node* temp = new Node(val,NULL,head);
    if (head == NULL) // if the list is empty
    {
      head = temp;
      tail = temp;
    }
    else // if the list has at least one node
    {
      head->setPrev(temp);
      head = temp;
    }
  }
  else // if the element to be added is in the middle or the end
  {
    

    Node* curr =head->getNext();
    Node* currTail = head;
    while(index >0 && curr!= NULL)
      {
        currTail = curr;
        curr = curr->getNext();
        index--;

        
      }
        if(curr != NULL) // element is in the middle
        {
          Node* temp = new Node(val,NULL,NULL);
          temp->setPrev(currTail);
          currTail->setNext(temp);
          temp->setNext(curr);
          curr->setPrev(temp); 
        }
    else // elemnt is in the end
        {
          if (curr == NULL && index == 0)
          {
            addAtTail(val);
            return;
          }
          else // index is out of bound
          {
            cerr<<"the index is out of bound"<<endl;
            return;
          }
        }
      
  }
  
  

     
}

void deleteAtIndex(int index) {
if (index< 0) //if the index is less than 0
{
  cerr<<"not a valid index "<<endl;
  return;
} 
else if (head == NULL) // if we are trying to delete from an empty list
{
  cerr<<"can not delete from an empty list"<<endl;
  return;
}
else
{
  Node *temp = head;
  if (index == 0) // if the index to be deleted is the first element
  {
    head = head->getNext();
    if (head == NULL) // if there is only 1 node
        tail = NULL;
    else
      head->setPrev(NULL);

   delete temp;
    temp = NULL;
  }
  else // if the element to be deleted is in the middle or the end
  {
    while (index > 0 && temp != NULL)
      {
        temp= temp->getNext();
        index--;
      }
    if (temp == NULL && index>=1)
    {
      cerr<<"index out of bound"<<endl;
      return;
    }
    else
    {
      if (temp != NULL)
      {
        temp->getPrev()->setNext(temp->getNext());
        temp->getNext()->setPrev(temp->getPrev());
      }
      else
      {
        tail = temp->getPrev();
        tail->setNext(NULL);
      }

      delete temp;
      temp = NULL;
      
    }
    
    
    
  }
}

}

void printForward()
{
  if (head == NULL)
    cerr<< "The linked list is Empty"<< endl;
  else
  {
    Node* curr = head;
    while (curr != NULL)
      {
        cout<< curr->getData()<<"  ";
        curr = curr->getNext();
      }
    cout<<endl;
  }
}

void printBackward()
{
  if (head == NULL)
    cerr<<"the linked list is empty "<<endl;
  else
  {
    Node* curr = tail;
    while(curr != NULL)
      {
        cout<< curr->getData()<<"  ";
        curr = curr->getPrev();
      }
    cout<<endl;
  }
}


};



int main() {


MyDoubleLinkedList l;

  l.addAtHead(0);
  l.addAtTail(1);
  l.addAtTail(2);
  l.printForward();
  l.printBackward();
  l.addAtIndex(1, 11);
    l.printForward();
  l.printBackward();
  l.addAtIndex(0, 10);
    l.printForward();
  l.printBackward();
  l.addAtIndex(4, 12);
   l.printForward();
  l.printBackward();
  l.addAtIndex(5, 13);
  l.printForward();
  l.printBackward();
    l.addAtIndex(7, 14);
  l.printForward();
  l.printBackward();
  l.deleteAtIndex(0);
    l.printForward();
  l.printBackward();
  l.deleteAtIndex(7);
  l.printForward();
  l.printBackward();
  l.deleteAtIndex(1);
  l.printForward();
  l.printBackward();
  l.deleteAtIndex(3);
  l.printForward();
  l.printBackward();
  bool found = l.search(13);
  if (found)
    cout<<"found 13"<<endl;
  else
    cout<<"13 was not found"<<endl;

  found = l.search(12);
    if (found)
    cout<<"found 12"<<endl;
  else
    cout<<"12 was not found"<<endl;
  int i = l.get(0);
  cout<<i<<endl;
  i = l.get(3);
   cout<<i<<endl;
 i = l.get(2);
   cout<<i<<endl;
   i = l.get(1);
   cout<<i<<endl;
    i = l.get(4);
   cout<<i<<endl;
  
  
  return 0;
}

