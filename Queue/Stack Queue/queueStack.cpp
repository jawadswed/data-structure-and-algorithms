#define QUEUESTACK_CPP

#include <iostream>
#include <stack>

using namespace std;

class Queue
{
private:
    stack<int> s1, s2;

public:
    Queue() {}

    void insertElem(int data) // enqueue
    {

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(data);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    bool isEmpty()
    {
        return (s1.empty() && s2.empty());
    }

    void deleteElement() // dequeue
    {
        if (isEmpty())
        {
            cerr << "the queue is empty.. no element to be deleted" << endl;
        }
        else
        {
            cout << "deleting " << s1.top() << endl;
            s1.pop();
        }
    }

    int frontElem() //peek
    {
        if (!s1.empty())
            return s1.top();
        else
        {
            cerr << "the queue is empty and there is no front element.... returning 0 " << endl;
            return 0;
        }
    }

    void print()
    {
        if (s1.empty())
        {
            cerr << "the queue is empty" << endl;
        }
        else
        {
            cout << "printing from front to rear" << endl;
            while (!s1.empty())
            {
                cout << s1.top() << "  ";
                s2.push(s1.top());
                s1.pop();
            }
            cout << endl;
            cout << "printing from rear to front" << endl;
            while (!s2.empty())
            {
                cout << s2.top() << "  ";
                s1.push(s2.top());
                s2.pop();
            }
        }
       
    }
};