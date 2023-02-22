#include <iostream>
using namespace std;
class Largest
{
private:
    int num[100];
    int n;

public:
    void get_num(void)
    {
        cout << "Enter the total number of input: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the " << i + 1 << " number: ";
            cin >> num[i];
        }
    }

    int large(void);
    void display();
};

int Largest ::large()
{
    int max = num[0];
    for (int i = 0; i < n; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
    }
    return max;
}

void Largest ::display()
{
    cout << "The largest of inputted number is " << large() << endl; // "Nesting of member function large()"
}

int main()
{
    Largest data;
    data.get_num();
    data.display();
    return 0;
}