#include <iostream>
using namespace std;

// Without Using Extra Space O(1)

void SinMissing(int arr[], int length, int first, int last)
{
    int diff = first - 0; // Diffrence between first element and index 0
    for (int i = 0; i < length; i++)
    {
        if (arr[i] - i != diff)
        {
            cout << "The missing element is : " << i + diff << endl;
            break;
        }
    }
}

void MultMissing(int arr[], int length, int first, int last)
{
    int diff = first - 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                cout << "The missing element is : " << i + diff << endl;
                diff++;
            }
        }
    }
}
int main()
{
    // For single missing element in sorted array
    int arr1[] = {4, 5, 6, 7, 9, 10, 11, 12};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int first1 = 4;
    int last1 = 12;
    // SinMissing(arr1, len1, first1, last1);

    int arr2[] = {5, 6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19, 20};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int first2 = 5;
    int last2 = 20;
    MultMissing(arr2, len2, first2, last2);
    return 0;
}