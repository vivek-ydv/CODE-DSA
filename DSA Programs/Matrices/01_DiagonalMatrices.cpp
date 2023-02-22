#include <iostream>
using namespace std;

// Here we are not taking a 2d array so that we can optimise the space as most of the entries will be zero.
// With the help of 1d array(to store diagonal element) we had done it.
class Diagonal
{
private:
    int len;
    int *Arr;

public:
    Diagonal(int n)
    {
        this->len = n;
        Arr = new int[len];
    }
    void Setdata(int i, int j, int data)
    {
        if (i == j)
        {
            Arr[i - 1] = data;
        }
    }
    void Getdata(int i, int j)
    {
        if (i == j)
        {
            cout << "The value at (" << i << "," << j << ") is : " << Arr[i - 1] << endl;
        }
        else
        {
            cout << "The value at (" << i << "," << j << ") is : 0"<< endl;
        }
    }
    void display()
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (i == j)
                {
                    cout << Arr[i] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Diagonal d1(5);
    d1.Setdata(1, 1, 2);
    d1.Setdata(2, 2, 4);
    d1.Setdata(3, 3, 6);
    d1.Setdata(4, 4, 8);
    d1.Setdata(5, 5, 9);

    d1.Getdata(3, 3);
    d1.display();
    return 0;
}