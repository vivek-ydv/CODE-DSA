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

void iterInOrder(node *root)
{
    node *curr;
    stack<node *> st;
    curr = root;
    while (!(st.empty() && curr == nullptr)) // When both conditons becomes true then Binary Tree will be completly trversed
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

int main()
{
    node *root = NULL;
    node *newroot = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << endl
         << "InOrder traversal :" << endl;
    iterInOrder(newroot);
    return 0;
}