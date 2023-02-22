#include <bits/stdc++.h>
using namespace std;

// Disjoint data structure implementation
int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent); // Path Comperssion
}
void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int x = findPar(u, parent);
    int y = findPar(v, parent);
    if (rank[x] < rank[y])
    {
        parent[x] = y;
    }
    else if (rank[y] < rank[x])
    {
        parent[y] = x;
    }
    else
    {
        parent[y] = x;
        rank[x]++;
    }
}

int main()
{
    int N = 7;
    // Intialise the vectors of parent and rank
    vector<int> parent(N);
    for (int i = 0; i < N; i++)
        parent[i] = i;
    vector<int> rank(N, 0);

    // unionn(2, 3, parent, rank);
    // To check that belong to same component or not
    if (findPar(2, parent) != findPar(3, parent))
        cout << "Belongs to diff component";
    else
        cout << "Belongs to same component";

    return 0;
}