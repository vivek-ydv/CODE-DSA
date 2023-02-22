#include <iostream>
using namespace std;

int main()
{
    int osize, nsize;
    cout << "Enter the size of array ";
    cin >> osize;
    int *p = new int[osize];
    cout << "Enter the element" << endl;
    for (int i = 0; i < osize; i++)
    {
        cin >> p[i];
    }
    // Method to resize
    cout << "Enter the new size of array ";
    cin >> nsize;
    int *q = new int[nsize];
    for (int i = 0; i < osize; i++)
    {
        q[i] = p[i];
    }
    delete[] p;
    p = q;    // Both will point the same adress
    q = NULL; // q will not point anymore any location

    cout << "Enter the Other remained element" << endl;
    for (int i = osize; i < nsize; i++)
    {
        cin >> p[i];
    }
    cout<<"The entered elements are : ";
    for (int i = 0; i < nsize; i++)
    {
        cout << p[i] << " ";
    }

    return 0;
}