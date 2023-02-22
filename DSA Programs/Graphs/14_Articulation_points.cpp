#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &disc, vector<int> &low, vector<int> adj[], vector<int> &isArticulation)
{
    static int timer = 0;
    disc[node] = low[node] = timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent) // if adjcent node is the parent then continue as edge to parent will not be considerd as a back edge
            continue;

        if (disc[it] == -1) // if adj node is not visited perform dfs
        {
            dfs(it, node, disc, low, adj, isArticulation);
            low[node] = min(low[node], low[it]); // update the low value of current nodes by comparing with the adjcent nodes excluding the parent node
            child++;                             // for each dfs of adjacent node increase the number of child
            if (low[it] >= disc[node] && parent != -1)
            {
                isArticulation[node] = 1;
            }
        }
        else
        {
            // means that it's a back edge but why we are not checking the condition for the articulation point here????
            // Reason:- As backedge is the edge from a node to another node in the same componet so no need to check for AP it's in same component
            low[node] = min(low[node], disc[it]);
        }
    }

    // Another condition for AP
    if (parent == -1 && child > 1)
    {
        isArticulation[node] = 1;
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
    vector<int> isArticulation(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            dfs(i, -1, disc, low, adj, isArticulation);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isArticulation[i] == 1)
            cout << i << endl;
    }

    return 0;
}