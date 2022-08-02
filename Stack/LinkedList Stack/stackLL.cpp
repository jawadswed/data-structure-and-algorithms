
#include <iostream>
#include <stdlib.h> // used for free() to free alocated space in memeory


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

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int data) // function to push a new element to the top of the stack
    {
        Node *temp = new Node(data); // create new node
        if (top == NULL)             // if the stack is empty
        {
            top = temp;
            return;
        }
        // else
        temp->next = top;
        top = temp;
    }

    void pop() // fucntion to remove the top element in the stack
    {
        if (top == NULL) // if there is not elements in the stack
        {
            cerr << "the Stack is empty... there is no element to pop" << endl;
            return;
        }

        Node *curr = top;
        cout << "the element " << top->data << " is popped " << endl;
        top = top->next;
        free(curr);
    }

    int topElement() // function that returns the top element in the stack
    {
        if (top == NULL) // if there is not elements in the stack
        {
            cerr << "the Stack is empty... there is no element on the top" << endl;
            return -1;
        }

        return top->data;
    }

    int size() // function to return the size(number of elements) of the stack
    {
        if (top == NULL)
        {
            return 0;
        }

        Node *curr = top;
        int count = 0;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        return count;
    }

    bool isEmpty() // functions that return whether the stack is empty or not
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        if (top == NULL)
        {
            cerr << " no elements was found to be printed " << endl;
        }
        else
        {
            Node *curr = top;

            while (curr != NULL)
            {
                cout << curr->data << "  ";
                curr = curr->next;
            }
            cout << endl;
        }
    }

    void reverse() // function to reverse the stack
    {
        if (top == NULL) // no element to be reversed
        {
            cerr << "there is no elements in the stack to be reversed " << endl;
        }
        else if (top->next == NULL) // only one element so it cant be reversed
        {
            cout << "there is only one element in the stack so we cant reverse" << endl;
        }
        else // more than 1 element in the stack so we reverse them
        {
            Node *first = top;
            Node *second = first->next;
            Node *temp;

            while (second != NULL)
            {
                temp = second->next;
                second->next = first;
                first = second;
                second = temp;
            }
            top->next = NULL;
            top = first;
        }
    }
};