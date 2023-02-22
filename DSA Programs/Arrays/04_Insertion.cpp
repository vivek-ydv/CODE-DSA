#include <iostream>
using namespace std;
void insert(int a[], int size, int index, int ele)
{
    for (int i = size; i > index; i--)
    {
        a[i] = a[i - 1];
    }
    a[index]=ele;
}
void display(int a[], int size)
{
    for (int i = 0; i < size + 1; i++)
    {
        cout << a[i]<<" ";
    }
}
int main()
{
    int a[100], pos, ele, size;
    cout << "Enter the size of array (0<size<100) : ";
    cin >> size;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the position at which you want to insert:";
    cin >> pos;
    cout << "Enter the element";
    cin >> ele;
    insert(a, size, pos - 1, ele);
    display(a, size);

    return 0;
}