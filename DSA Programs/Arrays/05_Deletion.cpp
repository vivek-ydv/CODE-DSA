#include <iostream>
using namespace std;
void deleteion(int a[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        a[i] = a[i + 1];
    }
}
void display(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[100], pos, size;
    cout << "Enter thw size of array (0<size<100) : ";
    cin >> size;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the position at which you want to delete element:";
    cin >> pos;
    deleteion(a, size, pos - 1);
    display(a, size);

    return 0;
}