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

// Morris Treversal : For Inorder
vector<int> morrisInorder(node *root)
{
    node *curr = root;
    vector<int> res;
    while (curr)
    {
        if (curr->left == NULL)
        {
            // if left subtree not exit
            res.push_back(curr->data); // store the node value
            curr = curr->right;
        }
        else
        {
            node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                // it means that we had to create the thread and we still have to traverse its left
                prev->right = curr; // Making thread
                curr = curr->left;  // move to left part
            }
            else
            {
                // it means that prev->right == curr)
                // so there is thread from its left subtree righmost node to curr node, it means we had already traversed the left subtrre

                prev->right = NULL;        // remove the thread
                res.push_back(curr->data); // store the node value
                curr = curr->right;        // Move to right part
            }
        }
    }
    return res;
}
int main()
{
    node *root = NULL;
    node *newroot = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    vector<int> Inorder = morrisInorder(newroot);
    cout << endl
         << "InOrder traversal :" << endl;

    for (int i = 0; i < Inorder.size(); i++)
    {
        cout << Inorder[i] << " ";
    }

    return 0;
}