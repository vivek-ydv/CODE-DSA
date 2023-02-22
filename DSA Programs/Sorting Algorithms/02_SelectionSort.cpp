#include <iostream>
using namespace std;

// Function to get the index value of largest element
int getmaxindex(int *arr, int s, int e)
{
    int max = s;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }
    return max;
}
void Display(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}

void selection(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        // Find the maximum item index in the remaining array
        int last = length - 1 - i;
        int maxindex = getmaxindex(arr, 0, last);

        // Swap the maxindex with the last index of remining
        int temp = arr[maxindex];
        arr[maxindex] = arr[last];
        arr[last] = temp;
    }
}

int main()
{
    int arr[] = {1, 4, 2, 6, -3, 0, 7, -9};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection(arr, size);
    Display(arr, size);
    return 0;
}