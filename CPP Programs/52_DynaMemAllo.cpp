#include <iostream>
using namespace std;

int main()
{
    // Dynamic memory allocation
    int *a = NULL;
    a = new int;
    *a = 25;
    cout << "The value of a is " << *a << endl;
    delete a; // Deletion

    // We can simply decleare like this:
    float *b = new float(25.45);
    cout << "The value of b is " << *b << endl;
    delete b;

    // Dynamic allocation of array
    int size;
    cout << "Enter the size of array :" << endl;
    cin >> size;
    int *arr = new int[size];

    cout << "Enter elements of array :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Elements of the array are :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    
    delete[] arr; // Deleting dynamic allocating array
    return 0;
}