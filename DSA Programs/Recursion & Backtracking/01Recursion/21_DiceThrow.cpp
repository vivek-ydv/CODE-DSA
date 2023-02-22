#include <bits/stdc++.h>
using namespace std;
void dice(string p, int target)
{
    if (target == 0)
    {
        cout << p << " ";
        return;
    }
    for (int i = 1; i <= 6 && i <= target; i++)
    {
        dice(p + char(i + 48), target - i);
        //  dice(p + to_string(i) , target - i);   // both method can be used to hold integer in a string
    }
}

// If we have a dice which have more than 6 faces or less than 6 faces then ??
void diceface(string p, int target, int faces)
{
    if (target == 0)
    {
        cout << p << " ";
        return;
    }
    for (int i = 1; i <= faces && i <= target; i++)
    {
        dice(p + to_string(i), target - i); // method to hold integer in a string
    }
}

int main()
{
    dice("", 4);
    // diceface("", 8, 7); // target:8 & faces:7

    return 0;
}