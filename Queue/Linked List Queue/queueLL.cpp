#define QUEUELL_CPP

#include <iostream>
#include <cstdio>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void insertElement(int data) // elements in the queue are going to be inserted from the rear
    {
        Node *temp = new Node(data);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            temp->next = rear;
            rear = temp;
        }
    }

    void removeElement() // elements in the queue are going to be removed from the front
    {
        if (front == NULL)
        {
            cerr << "there is no elements in the queue to be removed" << endl;
        }
        else if (front == rear) // if we have one element in the queue to be deleted
        {
            Node *temp = rear;
            free(temp);
            front = NULL;
            rear = NULL;
        }
        
        else
        {
            Node *temp = rear;

            while (temp->next != front)
            {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
            front = temp;
        }
    }

    void print()
    {
        if (front == NULL)
        {
            cerr << "there is no elements in the queue to be printed" << endl;
        }
        else
        {
            Node *temp = rear;
            cout<<"the front element is "<<front->data<< " and the rear element is "<<rear->data<<endl;
            while (temp != NULL)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    int numOfElem()
    {
        if (front == NULL)
        {
            return 0;
        }
        else
        {
            Node *temp = rear;
            int count = 0;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
};
