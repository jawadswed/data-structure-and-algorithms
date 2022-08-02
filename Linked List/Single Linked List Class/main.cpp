

#include <iostream>


using namespace std;

class Node
{
public:
int data;
Node* next;
Node(int x){
    data = x;
    next = NULL;
}
};
class MyLinkedList {
public:
    Node* head;

 MyLinkedList() {
    head = NULL;
}

int get(int index)  // function to return the element at the specified index 
{
    
    if(head == NULL || index < 0) // if the list is empty or the index is less than 0
        return -1;
    
    Node* temp = head;
    
    while(index != 0) // we go to the specified index
    {
        if(temp == NULL)
            return -1;
        temp = temp->next;
        index--;
    }
    
    if(temp == NULL)
        return -1;
    return temp->data;
}

void addAtHead(int val) // fucntion to add a new node with the given value to the head of the list
{
    
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void addAtTail(int val) // fucntion to add a new node with the given value to the end of the list
{
     
     Node* temp = new Node(val);
     if(head == NULL){
         head = temp;
         return;
     }
    
     Node* curr = head;
     while(curr->next != NULL){
         curr = curr->next;
     }
    
     curr->next = temp;
}

void addAtIndex(int index, int val) // function to add a node at the specified index and value to the list
{
     
     if(index == 0) // if the index is 0 then we just add to the head
         addAtHead(val);
     else if(index > 0 && head==NULL) // if the index is bigger than 0 but the list is emoty than we can add
         return;
     else{
         Node* curr = head;

         while(index != 1)
         {
             curr = curr->next;
             if(curr == NULL)
                 return;
             index--;
         }
         
         Node* temp = new Node(val);
         temp->next = curr->next;
         curr->next = temp;

     }
}

void deleteAtIndex(int index) // function to delete the node at the specified Index
 {
    if(index < 0)
        return;
    
    if(head == NULL)
        return;
    
    if(index == 0){
        head = head->next;
        return;
    }
    
    Node* curr = head;
    while(index != 1){
        curr = curr->next;
        if(curr == NULL)
            return;
        index--;
    }
    
    if(curr->next && curr->next->next != NULL){
        curr->next = curr->next->next;
    }else{
        curr->next = NULL;
    }
}

void print()
{
  if (head == NULL)
    cout<< "The linked list is Empty"<< endl;
  else
  {
    Node* curr = head;
    while (curr != NULL)
      {
        cout<< curr->data<<"  ";
        curr = curr->next;
      }
    cout<<endl;
  }
}

void reverse() // function to reverse the linked list 
{
  if (head == NULL)
  {
    cerr<<"the list is empty and cant be reversed"<<endl;
  }
  else if (head->next == NULL)
  {
    cerr<<"the list has one element and cant be reversed"<<endl;
  }
  else
  {
    Node *first = head;
    Node *second = first->next;
    Node *temp;
    while (second != NULL)  
      {
        temp = second->next;
        second->next =first;
        first = second;
        second = temp;
      }
    head->next = NULL;
    head = first;
  }
  
}
void copyArraytoLinkedList(int arr[], int size)
{
  for (int i = 0; i<size; i++)
    {
      addAtTail(arr[i]);
    }
}


void copyArraytoLinkedListBackward (int arr[], int size)
{
  for (int i = 0; i<size; i++)
    {
      addAtHead(arr[i]);
    }
}


};







int main() {

  MyLinkedList l;
  l.print();
  l.addAtHead(1);
 
  l.addAtTail(2);
  l.addAtTail(3);
  l.addAtTail(4);
  l.addAtTail(5);
  l.print();
  l.addAtIndex(2, 3);
  l.print();
  l.addAtIndex(0, 0);
  l.print();
  l.addAtIndex(0, 0);
  l.print();
  l.deleteAtIndex(0);
  l.print();
  MyLinkedList newl;
  int arr [] = {1,2,3,4,5,6};
  int size = sizeof(arr)/ sizeof(arr[0]);
  newl.copyArraytoLinkedList(arr, size);
  newl.print();
  l.print();
  l.reverse();
  l.print();

  
  
  return 0;
}

