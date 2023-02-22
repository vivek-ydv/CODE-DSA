#include <iostream>
using namespace std;
void duplicate(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int count = 1;
        if (arr[i] != -1)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    arr[j] = -1;
                }
            }
        }
        if (count > 1)
        {
            cout << "Element : " << arr[i] << " & Freq : " << count << endl;
        }
    }
}
int main()
{
    int arr[] = {8, 6, 4, 6, 5, 6, 2, 7, 8, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    duplicate(arr, len);
    return 0;
}