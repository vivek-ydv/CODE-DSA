#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    // Constructor
    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{
    cout << "Enter the data:";
    int data;
    cin >> data;
    root = new node(data); // root node created;

    if (data == -1) // base conditon that is no more child exit in left or right of a node
        return NULL;

    cout << "Enter the data for inserting in the left of " << data << endl;
    // recursive call for inserting the left child of a node
    root->left = buildtree(root->left);

    cout << "Enter the data for inserting in the right of " << data << endl;
    // recursive call for inserting the right child of a node
    root->right = buildtree(root->right);

    return root;
}
int main()
{
    node *root = NULL;
    buildtree(root);
    return 0;
}