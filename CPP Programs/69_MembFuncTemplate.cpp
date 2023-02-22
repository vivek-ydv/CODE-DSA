#include <iostream>
using namespace std;

template <class T>
class Vivek
{
    T data;

public:
    Vivek(T a)
    {
        data = a;
    }
    void display();
};
template <class T>
void Vivek<T> :: display()
{
    cout << "The value of data is : " << data << endl;
}
int main()
{
    Vivek<float> v1(5.6);
    v1.display();
    return 0;
}