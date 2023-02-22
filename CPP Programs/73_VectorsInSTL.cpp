#include <iostream>
#include <vector>
using namespace std;
template <class T>
void display(vector<T> &v)
{
    cout << "Dispalying the vector: ";
    for (int i = 0; i < v.size(); i++) // v.size() returns the size of vector (array) 'v'
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec1; // Decleration of vector(zero Length integer vector)
    int element, length;
    cout << "Enter the length of vector ";
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cout << "Enter the element to add to this vector:";
        cin >> element;
        vec1.push_back(element); // Add element at the end
    }
    display(vec1);

    cout << "The first element of vec1 is " << vec1.front() << endl; // Returns the first element of the vector
    cout << "The last  element of vec2 is " << vec1.back() << endl;  // Returns the last  element of the vector
    vec1.pop_back();                                                 // Removes the last element
    display(vec1);

    /*
        vector<int>::iterator begiter = vec1.begin(); // It(iterator) will be point to the the first element of the vector
        vector<int>::iterator enditer = vec1.end();   // It(iterator) will be point to the the last  element of the vector
        vec1.insert(begiter, 19);                     // Insert the value 19 before the first element
        vec1.insert(enditer, 19);                     // Insert the value 19 after  the last  element
        vec1.insert(begiter + 1, 19);                 // Insert the value 19 before the second element
        vec1.insert(begiter + 2, 5, 19);              // Insert the five copies of value 19 before the third element
        display(vec1);
    */

    // OTHERS WAYS TO DECLEARE THE THE VECTOR
    vector<char> vec2(4); // 4 element character vector
    vec2.push_back('J');
    display(vec2);

    vector<char> vec3(vec2); // 4 element charactor vector from the vector vec2
    display(vec3);

    vector<int> vec4(6, 2); // 6 elements of 2's
    display(vec4);
    cout << "The size of vec4 is " << vec4.size();

    return 0;
}
