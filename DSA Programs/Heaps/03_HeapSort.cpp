#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i;
    int r = 2 * i + 1;

    // If left child is larger than root
    if (l <= n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r <= n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root(current node)
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

int main()
{
    int arr[6] = {-1, 55, 53, 54, 52, 50};
    int n = 5;
    int size = n;
    while (size > 1)
    {
        // Swap root and last node
        swap(arr[1], arr[size]);
        size--;
        // Move root to its correct index
        heapify(arr, size, 1);
    }
    cout << "Sorted array :";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}