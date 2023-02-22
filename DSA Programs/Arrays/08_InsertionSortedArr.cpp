#include <iostream>
using namespace std;

int main()
{
    int numofele = 8;
    int arr[10] = {1, 2, 5, 7, 10, 15, 17, 20};
    int ele = 4;

    cout << "Before insertion ";
    for (int i = 0; i < (numofele); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int i = numofele - 1;
    while ( arr[i] > ele)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i+1] = ele;
    numofele++;

    cout << "After  insertion ";
    for (int i = 0; i < (numofele); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}