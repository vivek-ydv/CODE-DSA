#include <iostream>
using namespace std;

void Display(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Merging the subarrys
void merge(int *arr, int s, int m, int e)
{
    int i = s;
    int j = m + 1;
    int k = 0;

    int *mix = new int[e - s];

    while (i <= m && j <= e)
    {
        if (arr[i] < arr[j])
        {
            mix[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            mix[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= m)
    {
        mix[k] = arr[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        mix[k] = arr[j];
        j++;
        k++;
    }

    Display(mix, (e - s) + 1);

    // modifying the original array at proper index
    for (int l = 0; l <= (e - s); l++)
    {
        arr[l + s] = mix[l];
    }
}

void mergeSort(int *arr, int s, int e)
{
    if (e - s < 1)
    {
        return;
    }
    else
    {
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}
int main()
{
    int arr[] = {7, -3, 0, 5, 6, 7, 15, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);

    cout << endl
         << "After sorting :";
    Display(arr, size);
    return 0;
}