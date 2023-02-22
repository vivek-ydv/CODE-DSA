#include <iostream>
#include <string>
using namespace std;

class binary
{
private:
    string s;
    void chk_bin(void); // Only function inside this class can acess this function
public:
    void read(void);
    void ones_compliment(void);
    void display(void);
};

void binary ::read(void)
{
    cout << "Enter a binary number: ";
    cin >> s;
}

void binary ::chk_bin(void)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Wrong binary code" << endl;
            exit(0);
        }
    }
}

void binary ::ones_compliment(void)
{
    chk_bin(); // Its nesting of member function, i.e. a function is  used inside a function

    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '1')
        {
            s.at(i) = '0';
        }
        else
        {
            s.at(i) = '1';
        }
    }
}

void binary ::display()
{
    cout << "The binary number is: ";
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}

int main()
{
    binary num;
    num.read();
    // num.chk_bin(); // It will throw an error as it is private member function
    num.display();
    num.ones_compliment();
    num.display();

    return 0;
}