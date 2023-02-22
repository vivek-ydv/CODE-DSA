/*
SYNTAX(Class Template):->
-----------------------------------------
templete<class T>
class classname
{
   class specification,
   Where T can be char, int, float etc...
}; 
-----------------------------------------
*/

#include <iostream>
using namespace std;

template <class T>
class Vector
{
private:
    int size;

public:
    T *arr;
    Vector(int m)
    {
        size = m;
        arr = new T[size];
    }
    T dotproduct(Vector &v)
    {
        T sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = sum + this->arr[i] * v.arr[i]; // Note: this pointer will point to object which invokes the member function
        }
        return sum;
    }
};
int main()
{
    Vector<float> v1(3);
    v1.arr[0] = 2.1;
    v1.arr[1] = 4.2;
    v1.arr[2] = 6.3;

    Vector<float> v2(3);
    v2.arr[0] = 1.4;
    v2.arr[1] = 3.5;
    v2.arr[2] = 5.6;

    float val = v1.dotproduct(v2);
    cout << "The dot product of two vector is : " << val;
    return 0;
}
