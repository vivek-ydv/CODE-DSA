#include <bits/stdc++.h>
using namespace std;
/**************************VERY IMP CONCEPT***************************/
/************************Maximise The Minimum************************/

bool isPossible(vector<int> arr, int mid, int k)
{
    int cowsCount = 1;
    int lastPos = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if ((arr[i] - lastPos) >= mid) // If the distence between two stalls is greater or equal to mid.
        {
            cowsCount++;
            lastPos = arr[i]; // Since we have the put cow at this position hence update the lastposition.
            if (cowsCount == k)
            {
                return true;
            }
        }
    }
    return false;
}

int aggresiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int min = arr[0];
    int max = arr[(arr.size() - 1)];

    int ans = -1;
    int start = 0;       // Minimum distence will be 0 that is if we put all the cows in a single stall.
    int end = max - min; // Maximum possible distence between any two cows.

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, mid, k))
        {
            ans = mid;       // Store it as a one of the potential answar.
                             // Since we are able to put all 'k' cows in this minimum value but we have to minimise it.
            start = mid + 1; // hence we will look for more potential answar on the right side of thi value.
        }
        else
        {
            // Means that we are not able to put 'k' cows with this minimum distence,
            // It means that minimum distence is larger hence we have to reduce the minimum distence i.e. mid value.
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3;
    cout << aggresiveCows(stalls, k);
    return 0;
}