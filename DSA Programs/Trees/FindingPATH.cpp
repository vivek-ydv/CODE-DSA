#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

// We can use this method template in finding path problem :
bool traverse(TreeNode *root, int target, string &path)
{
    if (root == NULL)
        return false;

    if (root->val == target)
        return true;
    
    path.push_back('L');
    bool left = traverse(root->left, target, path);
    if (left)
        return true;
    else
        path.pop_back();

    path.push_back('R');
    bool right = traverse(root->right, target, path);
    if (right)
        return true;
    else
        path.pop_back();

    // if node is not found in any possible path
    return false;
}
int main()
{
    return 0;
}