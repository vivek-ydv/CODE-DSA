#include <bits/stdc++.h>
using namespace std;

vector<int> Search2d(vector<vector<int>> vec, int target)
{
    vector<int> res;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return {-1, -1};
}
int main()
{
    vector<vector<int>> vec = {{24, 4, 1, 7},
                               {18, 12, 3, 9},
                               {78, 88, 99, 56},
                               {18, 17, 32, 21}};

    vector<int> res = Search2d(vec, 88);
    for (auto &&i : res)
    {
        cout << i << " ";
    }

    return 0;
}