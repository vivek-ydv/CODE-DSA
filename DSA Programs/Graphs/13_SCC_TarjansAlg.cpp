#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<int> &disc, vector<int> &low, stack<int> &mystack, vector<bool> &presentInStack)
{
    static int timer = 0;
    disc[node] = low[node] = timer++;
    mystack.push(node);
    presentInStack[node] = true;

    for (auto it : adj[node])
    {
        if (disc[it] == -1) // if it is not visited
        {
            DFS(it, adj, disc, low, mystack, presentInStack);
            // after completion of function call for all adjcent update the low value
            low[node] = min(low[node], low[it]);
        }

        // IF visited then Check whether it's back edge or not,
        else if (presentInStack[it]) // Back egde case
        {
            low[node] = min(low[node], disc[it]);
        }
    }

    // check for head of SCC
    if (low[node] == disc[node])
    {
        cout << "SCC is:";
        while (mystack.top() != node)
        {
            cout << mystack.top() << ",";
            presentInStack[mystack.top()] = false;
            mystack.pop();
        }
        cout << mystack.top() << endl;
        presentInStack[mystack.top()] = false;
        mystack.pop();
    }
}
int main()
{
    int it = 7;
    vector<int> adj[it];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);
    adj[4].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(6);
    adj[6].push_back(5);

    vector<int> disc(it, -1), low(it, -1);
    vector<bool> presentInStack(it, false); // Avoids cross-edge
    stack<int> mystack;

    for (int i = 0; i < it; i++)
    {
        if (disc[i] == -1)
        {
            DFS(i, adj, disc, low, mystack, presentInStack);
        }
    }

    return 0;
}