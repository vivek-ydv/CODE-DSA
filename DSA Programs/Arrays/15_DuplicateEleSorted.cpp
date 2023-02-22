#include <iostream>
using namespace std;

// Time complexity = O(n)
// Space Complexity = O(1)

void Duplicate(int arr[], int n)
{
    int lastduplicate = 0;
    for (int i = 0; i < n; i++)
    {
        /*
        // When you have to print the only duplicate element(one time) not their frequency count.
        if (arr[i] == arr[i + 1] && arr[i] != lastduplicate)
        {
            cout << "Duplicate element : " << arr[i];
            lastduplicate = arr[i];
        }
        */

        // For printing duplicate element(one time) and their frequency count both.
        if (arr[i] == arr[i + 1])
        {
            cout << "Duplicate element : " << arr[i];
            int count = 1;
            int j = i + 1;
            while (arr[j] == arr[i])
            {
                count++;
                j++;
            }
            i = j - 1; // now 'i' will point to the last duplicate element,
                       // So that after this i++ will happen then 'i' will be pointing to the element next to the duplicate element and will not skip any element
            cout << " & freq :" << count << endl;
        }
    }
}
int main()
{
    int arr[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 17, 20, 20, 20, 20, 25};
    int len = sizeof(arr) / sizeof(arr[0]);
    Duplicate(arr, len);
    return 0;
}