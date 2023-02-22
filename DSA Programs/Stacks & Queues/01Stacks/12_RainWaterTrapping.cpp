#include <bits/stdc++.h>
using namespace std;

int trapWater(vector<int> &height)
{
    int size = height.size();
    int maxL[size];
    int maxR[size];

    // To get the max value to left of each building
    maxL[0] = height[0]; // intialisation
    for (int i = 1; i < size; i++)
    {
        maxL[i] = max(height[i], maxL[i - 1]);
    }

    // To get the max value to right of each building
    maxR[size - 1] = height[size - 1]; // intialisation
    for (int i = size - 2; i >= 0; i--)
    {
        maxR[i] = max(height[i], maxR[i + 1]);
    }

    // Calculate the water stored above each building and sumup them to get the total water stored
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res = res + (min(maxL[i], maxR[i]) - height[i]);
    }
    return res;
}
int main()
{
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vector<int> height = {4, 2, 0, 3, 2, 5};
    vector<int> height = {3, 0, 0, 2, 0, 4};

    cout << "Total water trapped is : " << trapWater(height) << " units.";
    return 0;
}