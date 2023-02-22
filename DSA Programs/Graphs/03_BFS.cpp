#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, 0); // declearing a visited array intilised all values as '0'
    queue<int> q;
    vector<int> bfs;
    // since graph may be disconnected so run a for loop
    for (int i = 1; i <= V; i++) // as our graph follows 1 based indexing
    {
        if (!vis[i]) // perform bfs
        {
            q.push(i);
            vis[i] = 1;
            while (q.empty())
            {
                int curr = q.front();
                q.pop();
                bfs.push_back(curr);
                for (auto it : adj[curr])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}
int main()
{

    return 0;
}