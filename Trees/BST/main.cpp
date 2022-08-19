#include <iostream>
// #include <stack>
// #include <queue>
// #include "singleLL.cpp"
// #include "stackLL.cpp"
// #include "stackArray.cpp"
// #include "queueLL.cpp"
// #include "queueArray.cpp"
// #include "queueStack.cpp"
#include <cstdlib>
#include "Btree.cpp"

using namespace std;

/*
The performance of the search algorithm 
depends on the shape of the tree
 All operations in a BST are performed in O(h), 
where h is the height of the tree
 Unfortunately, h may be as large as n for 
a degenerate tree.
 The main advantage of binary searching, O(log n) 
search time, may be lost if the BST is not balanced. 
In the worst case, the search time may be O(n).

*/

int main()
{
    Btree tree;
    
    // this is not the way to best insert to a tree to make it balanced 
    // the best way is to choose the root to be the middle (at every suBtree)
    for (int i = 0; i < 10; i++)
    {
        int j = rand() % 100;
        cout << "inserting " << j << endl;
        tree.insert(j);
    }
   int h = tree.height();

   cout<<"the height of the tree is "<<h<<endl;


    tree.search(2) ? cout << "found 2 in the first tree" << endl : cout << "2 was not found in the first tree" << endl;
    tree.search(20) ? cout << "tree 1 found 20" << endl : cout << "tree 1 20 was not found " << endl;

    cout << "tree 1 post order " << endl;
    tree.postorderPrint();
    cout << endl;
    cout << "tree 1 pre order " << endl;
    tree.preorderPrint();
    cout << endl;
    cout << "tree 1 In order " << endl;
    tree.inorderPrint();
    cout << endl;
    cout << "tree 1 deleting 41 (the root)" << endl;
    tree.deleteNode(41);
    cout << "tree 1 post order " << endl;
    tree.postorderPrint();
    cout << endl;
    cout << "tree 1 pre order " << endl;
    tree.preorderPrint();
    cout << endl;
    cout << "tree 1 In order " << endl;
    tree.inorderPrint();
    cout << endl;
    cout<<"tree 1 adding back 41"<<endl;
    tree.insert(41);
    cout << "tree 1 post order " << endl;
    tree.postorderPrint();
    cout << endl;
    cout << "tree 1 pre order " << endl;
    tree.preorderPrint();
    cout << endl;
    cout << "tree 1 In order " << endl;
    tree.inorderPrint();
    cout << endl;

    

    return 0;
}