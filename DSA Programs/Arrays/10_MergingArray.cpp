#include <iostream>
using namespace std;
//  MERGING OF TWO ARRAYS
//  Condition : Both Arrays Must be sorted
void Merge(int arr1[], int arr2[], int arr3[], int len1, int len2)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    // For remaining element in one of the two arrays
    // One of the following loop will be executed according to value of i and j
    for (; i < len1; i++)
    {
        arr3[k] = arr1[i];
        k++;
    }
    for (; j < len2; j++)
    {
        arr3[k] = arr2[j];
        k++;
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr1[] = {2, 6, 7, 9, 12};
    int arr2[] = {3, 5, 8, 10, 14};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[len1 + len2];

    Merge(arr1, arr2, arr3, len1, len2);

    cout << "First  array : ";
    display(arr1, len1);
    cout << "Second array : ";
    display(arr2, len2);
    cout << "Merged array : ";
    display(arr3, len1 + len2);
    return 0;
}