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

/************************************************************INSERTION IN BST**********************************************************************/
node *insertIntoBST(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
node *takeInput(node *root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}
/***************************************************************************************************************************************************/
void LevelOrder(node *root)
{
    queue<node *> q;
    q.push(root); // Push the root into the queue
    q.push(NULL); // Pushing the seprator

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        if (current == NULL) // It means that purana level traverse ho chuka hai
        {
            cout << endl;
            if (!q.empty()) // It means that queue still has some child nodes
            {
                q.push(NULL); // Push separator
            }
        }
        else
        {
            cout << current->data << " "; // Print the current node value

            // First check if childs exist then only push
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
}
int main()
{
    node *root = NULL;
    cout << "Enter data to create BST :";
    root = takeInput(root);
    // 10 8 21 7 27 5 4 3 -1
    cout << "Levelorder traversal :" << endl;
    LevelOrder(root);
    return 0;
}