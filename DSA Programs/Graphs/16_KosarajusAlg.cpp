#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            DFS(it, vis, adj, st);
        }
    }
    st.push(node);
}

void revDFS(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            revDFS(it, vis, transpose);
        }
    }
}
int main()
{
    int n = 7;
    vector<int> adj[n];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);
    adj[4].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(6);
    adj[6].push_back(5);

    stack<int> st;
    vector<int> vis(n, 0);

    // Get nodes in order of their finishing time : toposort
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            DFS(i, vis, adj, st);
    }

    // Do transpose(reverse all the connections)
    vector<int> transpose[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    // Pop from stack and do dfs
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cout << "SCC:";
            revDFS(node, vis, transpose);
            cout << endl;
        }
    }

    return 0;
}