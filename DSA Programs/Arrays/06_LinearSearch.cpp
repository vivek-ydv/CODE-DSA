#include <iostream>
using namespace std;
// Time complexity Big O(n)
int main()
{
    int arr[50] = {1, 3, 4, 6, 7, 9, 10, 12, 13, 15};
    int ele = 12;
    int length = 10;
    int flag = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == ele)
        {
            cout << "Element " << ele << " found at " << i + 1 << " position";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Not found";
    }

    return 0;
}