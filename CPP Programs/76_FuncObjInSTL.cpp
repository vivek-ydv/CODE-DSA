#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
void display(int *arr)
{
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // Function Object (Functor) : Functions wrapped in a class so that it is avilable like an object.

    int arr[] = {1, 5, 7, 4, 8, 2};
    sort(arr, arr + 6); // Sort in ascending order
    display(arr);
    sort(arr, arr + 6, greater<int>()); // Sort in decending order
    display(arr);

    return 0;
}