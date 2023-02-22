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

void RevLevelOrder(node *root)
{

    queue<node *> q;
    q.push(root); // Push the root into the queue
    q.push(NULL); // Pushing the seprator

    stack<node *> st;
    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        if (current == NULL) // It means that purana level traverse ho chuka hai
        {
            st.push(NULL);
            if (!q.empty()) // It means that queue still has some child nodes
            {
                q.push(NULL); // Push separator
            }
        }
        else
        {
            // Push the current node into stack
            st.push(current);

            // First check if childs exist then only push
            if (current->right)
                q.push(current->right);
            if (current->left)
                q.push(current->left);
        }
    }
    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        if (temp == NULL)
            cout << endl;
        else
            cout << temp->data << " ";
    }
}

int main()
{
    node *root = NULL;
    node *newroot = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Level Order traversal :" << endl;
    RevLevelOrder(newroot);
    return 0;
}