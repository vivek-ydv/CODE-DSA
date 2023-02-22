#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
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
    root->left = buildtree(root->left);
    cout << "Enter the data for inserting in the right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

/*********** Logic FOr this problem ***********/

void inOrder(node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    node *newroot = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<endl;
    cout << "Inorder traversal   :";
    inOrder(newroot);
    cout<<endl;
    cout << "Preorder traversal  :";
    preOrder(newroot);
    cout<<endl;
    cout << "Postorder taeversal :";
    postOrder(newroot);
    cout<<endl;
    return 0;
}