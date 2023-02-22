#include <iostream>
using namespace std;

void quicksort(int *arr, int low, int high)
{
    if (low > high)
    {
        return;
    }

    int s = low;
    int e = high;
    int m = (s + e) / 2;
    int pivot = arr[m];

    while (s <= e)
    {
        while (arr[s] < pivot)
        {
            s++;
        }
        while (arr[e] > pivot)
        {
            e--;
        }
        if (s <= e)
        {
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }

    // Now my pivot at correct index so index have to sort the two halves
    quicksort(arr, low, e);
    quicksort(arr, s, high);
}

int main()
{
    int arr[] = {7, -3, 0, 5, 6, 7, 15, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, size - 1);

    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}