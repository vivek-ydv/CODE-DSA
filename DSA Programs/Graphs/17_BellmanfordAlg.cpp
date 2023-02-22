#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    int n = 6, m = 7, source = 1;
    vector<node> edges;
    // Constructing the graph
    edges.push_back(node(0, 1, 5));
    edges.push_back(node(1, 2, -2));
    edges.push_back(node(1, 5, -3));
    edges.push_back(node(2, 4, 3));
    edges.push_back(node(3, 2, 6));
    edges.push_back(node(3, 4, -2));
    edges.push_back(node(5, 3, 1));

    int src = 0;
    int inf = 10000000;
    vector<int> dist(n, inf);
    dist[src] = 0;

    // relax all edges (n-1) times
    bool updated;
    for (int i = 0; i < n - 1; i++)
    {
        updated = false;
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
                updated = true;
            }
        }
        if (!updated)
        {
            // for any step if value of distence does not changes then there is no need to do further relaxation,
            // therfore break the loop as we already have the shortest path
            break;
        }

        // Now check by relaxing once more times if we have a negative edge cycle
        int flag = 0;
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
                flag = 1;
                break;
            }
        }

        // print the shortest distence to each node
        if (!flag)
        {
            for (int i = 0; i < n; i++)
            {
                cout << dist[i] << " ";
            }
        }
        return 0;
    }