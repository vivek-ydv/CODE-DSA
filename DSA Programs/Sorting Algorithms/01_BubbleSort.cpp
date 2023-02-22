#include <iostream>
using namespace std;

void Display(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}

void Bubble(int *arr, int length)
{
    // Run the steps n-1 times
    for (int i = 0; i < length; i++)
    {
        bool swapped = false;
        // For each step, the max item will come at last respective index
        for (int j = 1; j < length - i; j++)
        {
            // Swap if the item is smaller than the previous item
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }

        // if you donot swap for a particular value if 'i' means the array is sorted hence stop the program
        if (!swapped) // i.e. (swapped == false)
        {
            break;
        }
    }

    // Displaying the sorted array
    Display(arr, length);
}

int main()
{
    int arr[] = {1, 4, 2, 6, -3, 0, 7, -9};
    int size = sizeof(arr) / sizeof(arr[0]);
    Bubble(arr, size);
    return 0;
}