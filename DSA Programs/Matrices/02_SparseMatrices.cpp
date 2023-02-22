#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele;

public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    void setdata()
    {
        cout << "Enter the non zero elements" << endl;
        for (int i = 0; i < num; i++)
        {
            cout << "For the " << i + 1 << " non zero element" << endl;
            cout << "Enter row : ";
            cin >> ele[i].i;
            cout << "Enter col : ";
            cin >> ele[i].j;
            cout << "Enter ele : ";
            cin >> ele[i].x;
        }
    }
    void display()
    {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ele[k].i == i && ele[k].j == j)
                {
                    cout << ele[k].x << " ";
                    k++;
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
    Sparse s1(4, 5, 5);
    s1.setdata();
    s1.display();

    return 0;
}
