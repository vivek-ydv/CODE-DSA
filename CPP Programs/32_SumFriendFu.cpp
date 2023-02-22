#include <iostream>
using namespace std;
class Second; // FORWARD DECLERATION
class First
{
private:
    int x;

public:
    void setx(int n1)
    {
        x = n1;
    }
    friend void sum(First, Second); // By this decleration function can acess the value of x
};

class Second
{
private:
    int y;

public:
    void sety(int n2)
    {
        y = n2;
    }
    friend void sum(First, Second); // By this decleration function can acess the value of y
};

// Here Friend function is used to bridge the two classes

void sum(First o1, Second o2)
{
    cout << "The sum is: " << (o1.x + o2.y);
}
int main()
{
    First n1;
    n1.setx(5);
    Second n2;
    n2.sety(14);

    sum(n1, n2);
    return 0;
}