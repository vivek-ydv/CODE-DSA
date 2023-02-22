#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topo(int N, vector<int> adj[])
    {
        queue<int> q;
        // vector array to store Indegree
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            // calculate indegree
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        // First push all vertex having indegree '0'
        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Perform BFS with some conditions
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                // Decrease the indegree value for all adjcent nodes & if any node's indegree becomes '0' push it into queue
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

int main()
{
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);

    Solution obj;
    vector<int> v = obj.topo(6, adj);
    for (auto it : v)
        cout << it << " ";

    return 0;
}