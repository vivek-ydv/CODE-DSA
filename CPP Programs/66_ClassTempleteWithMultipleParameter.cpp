#include <iostream>
using namespace std;
/*
templete<class T1, class T2.....(COMMA SEPRATED)>
class classname
{
   class specification[BODY]
}; 
*/
template <class T1, class T2>
class Myclass
{
    T1 data1;
    T2 data2;

public:
    Myclass(T1 a, T2 b)
    {
        data1 = a;
        data2 = b;
    }
    void showdata()
    {
        cout << "data1: " << this->data1 << endl
             << "data2: " << data2 << endl;
    }
};
int main()
{
    Myclass<float, char> obj1(2.7, 'V');
    obj1.showdata();

    Myclass<int, char> obj2(19, 'J');
    obj2.showdata();
    return 0;
}