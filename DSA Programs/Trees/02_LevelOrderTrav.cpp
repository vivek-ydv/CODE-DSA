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

/*********** Logic For this problem ***********/

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

void LevelOrder2(node *root)
{
    int level = 1;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int len = q.size();
        cout << "Printing the level " << level << " : ";
        for (int i = 0; i < len; i++)
        {
            auto curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        level++;
        cout << endl;
    }
}
int main()
{
    node *temp = NULL;
    node *root = buildtree(temp);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << endl << "Level Order traversal :" << endl;
    LevelOrder(root);
    LevelOrder2(root);
    return 0;
}