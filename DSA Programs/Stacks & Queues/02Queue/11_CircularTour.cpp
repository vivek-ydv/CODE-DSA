#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &fuel, vector<int> &cost)
{
    int deficit = 0; // to track the record how much fuel was needed if it fails from a start point
    int balance = 0; // to track how much fuel is remained after reaching to next position
    int start = 0;   // intital start point

    for (int i = 0; i < cost.size(); i++)
    {
        balance = balance + fuel[i];
        balance = balance - cost[i]; // Update the balance

        if (balance < 0)
        {
            deficit = deficit + balance;
            start = i + 1; // New start position if it fails from the previous start position
            balance = 0;   // Make the fuel balance zero as we are starting from the new positon
        }
    }
    if ((balance + deficit) >= 0)
        return start;
    else
        return -1;
}
int main()
{

    return 0;
}