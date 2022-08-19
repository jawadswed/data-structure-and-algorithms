#ifndef BTREE_CPP
#define BTREE_CPP

#include <iostream>


using namespace std;
/*
A binary search tree is arranged so that:
 Data is stored in order
 Data can be retrieved by value efficiently
 Each node is larger than the data in its left child
 Each node is smaller than the data in its right child
*/

struct node
{
    int key_value;
    node *left;
    node *right;
};

class Btree
{
public:
    Btree()
    {
        root = NULL;
    }
    ~Btree()
    {
        destroyTree();
    }
    bool isEmpty()
    {
        return (root !=NULL);
    }
    int height()
    {
        return height(root) -1; // because a root has height 0
    }
    void insert(int key)
    {
        if (root != NULL)
            insert(key, root);
        else
        {
            root = new node;
            root->key_value = key;
            root->left = NULL;
            root->right = NULL;
        }
    }

   
    void deleteNode(int data)
    {
        deleteNodes(data);
    }



    bool search(int key)
    {
        return search(key, root);
    }
    void destroyTree()
    {
        destroyTree(root);
    }
    void preorderPrint()
    {
        preorderPrint(root);
    }
    void postorderPrint()
    {
        postorderPrint(root);
    }
    void inorderPrint()
    {
        inorderPrint(root);
    }

private:
    void preorderPrint(node *leaf)
    // Visit the root first, then the children
    // Complete each child’s suBtree before the next child
    {
        if (leaf != NULL)
        {
            cout << leaf->key_value << " ";

            preorderPrint(leaf->left);
            preorderPrint(leaf->right);
        }
    }

    void postorderPrint(node *leaf)
    // Visit all children (each completely before the next), then the root
    {
        if (leaf != NULL)
        {
            postorderPrint(leaf->left);
            postorderPrint(leaf->right);
            cout << leaf->key_value << " ";
        }
    }

    void inorderPrint(node *leaf)
    // a node is visited after its left suBtree and before its right suBtree
    {
        if (leaf != NULL)
        {
            inorderPrint(leaf->left);
            cout << leaf->key_value << " ";
            inorderPrint(leaf->right);
        }
    }
//  void iterativeInsertNode(int data)
//     {
//         node *newNode = new node;
//         newNode->key_value = data;
//         newNode->left = NULL;
//         newNode->right = NULL;

//         node *temp = root;

//         node *parent = NULL;

//         while (temp != NULL)
//         {
//             parent = temp;

//             if (data >= temp->key_value)
//                 temp = temp->right;
//             else
//                 temp = temp->left;
//         }

//         if (parent == NULL) // case where the root is empty
//             root = newNode;
//         else if (data >= parent->key_value)
//             parent->right = newNode;
//         else
//             parent->left = newNode;
//     }

    int height(node *leaf)
    {
        if ( !leaf )
        {
            return 0;
        }
        else
        {
        int left = height(leaf->left);
        int right = height(leaf->right);
        if (left >= right)
            return left + 1;
        else
            return right + 1;
        }
        
    }

    void insert(int key, node *leaf)
    {
        if (key < leaf->key_value)
        {
            if (leaf->left != NULL)
                insert(key, leaf->left);
            else
            {
                leaf->left = new node;
                leaf->left->key_value = key;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        }
        else if (key >= leaf->key_value)
        {
            if (leaf->right != NULL)
                insert(key, leaf->right);
            else
            {
                leaf->right = new node;
                leaf->right->key_value = key;
                leaf->right->left = NULL;
                leaf->right->right = NULL;
            }
        }
    }

    bool search(int key, node *leaf)
    {
        if (leaf != NULL)
        {
            if (key == leaf->key_value)
                return true;
            else if (key < leaf->key_value)
                return search(key, leaf->left);
            else
                return search(key, leaf->right);
        }
        else
            return false;
    }
    void destroyTree(node *leaf)
    {
        if (leaf != NULL)
        {
            destroyTree(leaf->left);
            destroyTree(leaf->right);
            delete leaf;
        }
    }

    node *findMaximumKey(node *ptr) // helper funtion for the deleteNode 
    {
        while (ptr->right != nullptr)
        {
            ptr = ptr->right;
        }
        return ptr;
    }

    // void deleteNode(node *&root, int key)
    // {
    //     // base case: the key is not found in the tree
    //     if (root == nullptr)
    //     {
    //         cout<<"key was not found "<<endl;
    //         return;
    //     }

    //     // if the given key is less than the root node, recur for the left suBtree
    //     if (key < root->key_value)
    //     {
    //         deleteNode(root->left, key);
    //     }

    //     // if the given key is more than the root node, recur for the right suBtree
    //     else if (key > root->key_value)
    //     {
    //         deleteNode(root->right, key);
    //     }

    //     // key found
    //     else
    //     {
    //         // Case 1: node to be deleted has no children (it is a leaf node)
    //         if (root->left == nullptr && root->right == nullptr)
    //         {
    //             // deallocate the memory and update root to null
    //             delete root;
    //             root = nullptr;
    //         }

    //         // Case 2: node to be deleted has two children
    //         else if (root->left && root->right)
    //         {
    //             // find its inorder predecessor node
    //             // It is smaller than any other nodes that are greater than the node to remove
    //             //It is larger than any node in the left suBtree and smaller than any node in the right suBtree
    //             node *predecessor = findMaximumKey(root->right);
    //             cout<<"predecessor is "<<predecessor->key_value<<endl;
    //             // copy value of the predecessor to the current node
    //             root->key_value = predecessor->key_value;

    //             // recursively delete the predecessor. Note that the
    //             // predecessor will have at most one child (left child)
    //             deleteNode(root->left, predecessor->key_value);
    //         }

    //         // Case 3: node to be deleted has only one child
    //         else
    //         {
    //             // choose a child node
    //             // if the node has no left suBtree then we move up the right child
    //             // if the node has no right suBtree then we move up the left child
    //             node *child = (root->left) ? root->left : root->right;
    //             node *curr = root;

    //             root = child;

    //             // deallocate the memory
    //             delete curr;
    //         }
    //     }
    // }


    void deleteNodes(int data)
    { // this function deletes node from the BST
        if (root == NULL)
        {
            cout << "Tree Empty Please Insert values" << endl;
            return;
        }
        node *temp = root;   // pointer for traversing data if present
        node *parent = NULL; // trailing pointer that points to the parent node(intermediate nodes)
        while (temp != NULL)
        {
            if (data < temp->key_value)
            {
                parent = temp;
                temp = temp->left;
            }

            else if (data > temp->key_value)
            {
                parent = temp;
                temp = temp->right;
            }
            else
            {
                // looking for child nodes
                if (temp->left == NULL && temp->right == NULL)
                {
                    cout << "We are deleting a leaf node" << endl;
                    if (parent->left == temp)
                    {
                        parent->left = NULL;
                    }
                    else
                    {
                        parent->right = NULL;
                    }
                    free(temp);
                    return;
                }
                else if (temp->left == NULL || temp->right == NULL)
                {
                    cout << "We are deleting parent node which have one child" << endl;
                    if (temp->left != NULL&&data<root->key_value)
                    {
                        parent->left = temp->left;
                    }
                    else if(temp->right != NULL&&data>root->key_value)
                    {
                        parent->right = temp->right;
                    }
                    else if(temp->right != NULL&&data<root->key_value)
                    {
                      parent->left = temp->right;
                    }
                    else{
                      //checking if temp has no value in the right and data is greater than parent
                      //then the parent right value is temp's left value
                      parent->right = temp->left; 
                    }
                    free(temp);
                    return;
                }
                else
                {
                    cout << "Deleting Node which has two children" << endl;
                    // in this case we need to find the pre-order successor.
                    node *t = temp->right;
                    if (t->left == NULL && t->right == NULL)
                    {
                        temp->key_value = t->key_value;
                        temp->right = NULL;
                        cout<<"successor is "<<t->key_value<<endl;
                        free(t);
                        return;
                    }
                    else if (t->left == NULL && t->right != NULL)
                    {
                        temp->key_value = t->key_value;
                        temp->right = t->right;
                        cout<<"successor is "<<t->key_value<<endl;
                        free(t);
                        return;
                    }
                    while (t->left != NULL)
                    {
                        parent = t;
                        t = t->left;
                    }
                    temp->key_value = t->key_value;
                    parent->left = NULL;
                    cout<<"successor is "<<t->key_value<<endl;
                    free(t);
                    return;
                }
            }
        }
        cout << "No Nodes Found to delete" << endl;
        return;
    }



  
    node *root;
};

#endif
