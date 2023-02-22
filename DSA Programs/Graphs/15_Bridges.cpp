#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bridges;
void DFS(int node, int parent, vector<int> &disc, vector<int> &low, vector<int> adj[])
{
    static int timer = 0;
    disc[node] = low[node] = timer++;

    for (auto it : adj[node])
    {
        if (it == parent) // if adjcent node is the parent then continue as edge to parent will not be considerd as a back edge
            continue;

        if (disc[it] == -1) // if node is not visited perform dfs
        {
            DFS(it, node, disc, low, adj);
            // update the low value of current nodes by comparing with the adjcent nodes excluding the parent node
            low[node] = min(low[node], low[it]);

            if (low[it] > disc[node])
            {
                bridges.push_back({node, it});
            }
        }
        else
        {
            // means that it's a back edge but why we are not checking the condition for the bridge here????
            // Reason:- As backedge is the edge from a node to another node in the same componet so no need to check for bridge it's in same component
            low[node] = min(low[node], disc[it]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(n, -1);
    vector<int> low(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            DFS(i, -1, disc, low, adj);
        }
    }

    return 0;
}