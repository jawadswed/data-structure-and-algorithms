#define QUEUEARRAY_CPP

#include <iostream>

using namespace std;

const int SIZE = 128;

class Queue
{
private:
    int front;  // not really needed
    int rear;
    int size;
    int *qArray;
public:
    Queue(int s)
    {
        front = 0; 
        rear = 0;
        size = s;
        qArray = new int;
    }

    void insertElement (int data)
    {
        if (size == rear) // if the queue is full
        {
            cerr<<"The Queue is full.. Cant insert any more element"<<endl;
        }
        else
        {
            qArray[rear] = data;
            rear++;
        }
    }

    void deleteElement ()
    {
        if (front == rear) // if the queue is empty
        {
            cerr<<"cant delete from an empty queue"<<endl;
        }
        else
        {
            for (int i = 0 ; i< rear -1;i++)
            {
                qArray[i] = qArray[i+1];
            }
            rear--;
        }
    }

    int numOfElem ()
    {
        return rear;
    }

    int frontElem()
    {
        return qArray[front];
    }

    int rearElem()
    {
        return qArray[rear-1];
    }

    void print ()
    {
        if (front == rear)
        {
            cout<<"the queue is empty"<<endl;
        }
        else
        {
            cout<<"the front of the queue is "<<qArray[front]<<" the rear of the queue is  "<<qArray[rear-1]<<endl;
            for (int i = 0; i< rear; i++)
            {
                cout<<qArray[i]<<"  ";
            }
            cout<<endl;
        }
    }

    ~Queue() { delete[] qArray; }

};