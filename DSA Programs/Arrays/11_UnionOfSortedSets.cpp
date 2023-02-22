#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void setunion(int a[], int b[], int m, int n)
{
    // The idea is used to apprach of the merging of the two sorted array by making few changes in conditionals statement
    // Time complexity O(n)
    int c[100];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else if (b[j] < a[i])
        {
            c[k] = b[j];
            j++;
            k++;
        }
        else if (a[i] == b[j])
        {
            c[k] = a[i]; // or c[k] = b[j];
            i++;
            j++;
            k++;
        }
    }
    for (; i < m; i++)
    {
        c[k] = a[i];
        k++;
    }
    for (; j < n; j++)
    {
        c[k] = b[j];
        k++;
    }
    // Displaying the union set array[length of union set == value of k]
    for (int i = 0; i < k; i++)
    {
        cout << c[i] << " ";
    }
}
int main()
{
    //  Let us consider two sorted sets of array
    int a[] = {1, 3, 4, 5, 6, 9};
    int b[] = {2, 3, 6, 7, 9, 11};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    setunion(a, b, m, n);

    return 0;
}