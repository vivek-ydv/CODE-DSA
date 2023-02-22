#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void revarray(int *array, int n)
{
    int temp;
    int i = 0;
    while (i < n / 2)
    {
        temp = array[i];
        array[i] = array[(n - 1) - i];
        array[(n - 1) - i] = temp;
        i++;
    }
    cout << "The reversed array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}
int main(int argc, char const *argv[])
{
    int arr[1000];
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the elements of array :"<<endl;
    for (int i = 0; i < rows; i++)
    {
        cin >> arr[i];
    }
    revarray(arr, rows);

    return 0;
}
