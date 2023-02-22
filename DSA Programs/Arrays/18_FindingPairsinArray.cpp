#include <iostream>
using namespace std;
// Find all the pairs have sum equal to the k or 10
void Pairs1(int arr[], int length, int k) // Time Complexity = O(n^2)
{
    int count = 1;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {

            if (arr[i] + arr[j] == k)
            {
                cout << "Pair " << count << " : " << arr[i] << " & " << arr[j] << endl;
                count++;
            }
        }
    }
}

int main()
{
    int arr[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14}; // Assumning that array is free of duplicate element
    int len = sizeof(arr) / sizeof(arr[0]);

    int k = 10; // We have to find all the pairs in array have sum equal to the 10
    Pairs1(arr, len, k);
    return 0;
}