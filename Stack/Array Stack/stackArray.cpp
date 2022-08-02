#define STACKARRAY_CPP

#include <iostream>

using namespace std;

const int SIZE = 128;

class Stack
{

    int top;
    int *arr;

public:
    Stack()
    {
        top = -1;
        arr = new int[SIZE];
    }

    void push(int data) // function to push the data given to the stack
    {
        if (top >= SIZE - 1) // if the stack is full
        {
            cerr << "cant push.. Stack Overflow" << endl;
        }
        else // else insert the data into the array stack
        {
            top += 1;
            arr[top] = data;
        }
    }

    void pop() // function to remove the element from the top(end) of the stack array
    {
        if (top == -1)
        {
            cerr << " no elements in the stack was found to be popped" << endl;
        }
        else
        {
            cout << "the element " << arr[top] << " was popped" << endl;
            top--;
        }
    }

    int topElement() // function to return the top element in the stack array
    {
        if (top == -1)
        {
            cerr << "the stack is emoty " << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    int numOfElements() // fucntion to return the number of elements in the stack
    {
        if (top == -1)
        {
            cout<<"no eleements in the stack was found"<<endl;
            return 0;
        }
        else
        {
            return top+1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            cout<<"the stack is empty"<<endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        if (top == -1)
        {
            cerr<<"the stack is empty"<<endl;
        }
        else
        {
            for (int i = top; i>=0;i--)
            {
                cout<< arr[i]<<"  ";
            }
            cout<<endl;
        }
    }

    void reverse()
    {
        if (top == -1)
        {
            cerr<<"the stack is empty"<<endl;
        }
        else if (top == 0)
        {
            cout<<"the stack has only one element and cant be reveresed"<<endl;
        }
        else
        {
            int temp;
            for (int i = 0; i< top/2; i++)
            {
                 temp = arr[i];
                 arr[i] = arr[top-i];
                 arr[top-i] = temp;
            }
        }
    }

};