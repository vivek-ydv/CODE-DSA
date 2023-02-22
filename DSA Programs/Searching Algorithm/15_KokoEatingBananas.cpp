#include <bits/stdc++.h>
using namespace std;
int isPossible(vector<int> arr, int mid, int h)
{
    int hrsrequired = 0; // To count how many hrs will be required to finish all bananas
    for (int i = 0; i < arr.size(); i++)
    {
        // int remained = arr[i]; // Amount of bananas that is to be eaten
        // while (remained > 0)
        // {
        //     remained -= mid;
        //     hrsrequired++;
        // }
        hrsrequired += (arr[i] + mid - 1) / mid; // More optimised method to calculate tha hrs
    }
    if (hrsrequired <= h)
    {
        return true;
    }
    return false;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int ans = -1;
    int start = 1;
    int end = *max_element(piles.begin(), piles.end());

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(piles, mid, h))
        {
            ans = mid;     // Store it as one of the potential answars
            end = mid - 1; // Since we have to minmise it hence look on left side for more potential answars
        }
        else
        {
            // It means that koko is not able to eat the bananas with this speed in the given time,
            // hence we have to increase the speed that is increase the value of mid.
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 6;
    cout << minEatingSpeed(piles, h);
    return 0;
}