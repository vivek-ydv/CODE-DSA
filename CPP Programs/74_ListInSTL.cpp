#include <iostream>
#include <list>
using namespace std;
void display(list<int> &lst)
{
    cout << "Displaying the list : ";
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    int element, size;
    cout << "Enter the size of list:";
    cin >> size;
    list<int> list1; // List of 0 length
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element to add to this list ";
        cin >> element;
        list1.push_back(element);
    }
    display(list1);
    /*
    list1.pop_back(); // Delete element from last of list
    display(list1);
    list1.pop_front(); // Delete from start of the list
    display(list1);
    */

    /* Initialistion with help of iterator */
    list<int> list2(4); // Empty list of size 3
    list<int>::iterator iter = list2.begin();
    *iter = 9;
    iter++;
    *iter = 7;
    iter++;
    *iter = 8;
    iter++;
    *iter = 6;
    iter++;

    display(list2);

    // list2.remove(6);  // To delete a particular element from the list
    // display(list2);

    // list2.sort(); // Sorting the list
    // cout << "After sorting ";
    // display(list2);

    // list2.reverse(); // Reversing the list
    // cout << "After reversing ";
    // display(list2);

    // list1.swap(list2);
    // cout << "After swapping list 1 : ";
    // display(list1);
    // cout << "After swapping list 2 : ";
    // display(list2);
    // return 0;

    list1.merge(list2);
    cout << "After merging both";
    display(list1);
    return 0;
}