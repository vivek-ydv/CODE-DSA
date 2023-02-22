#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i which is an index of arr[] and n is the size of heap
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
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // nodes n/2 + 1 to n will be leaf nodes hence no need to process them
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "MAX HEAP :";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
