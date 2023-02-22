#include <iostream>
using namespace std;

class ShopItem
{
    int id;
    float price;

public:
    void setdata(int a, float b)
    {
        id = a;
        price = b;
    }
    void getdata()
    {
        cout << "Code of this item is:" << id << endl;
        cout << "Price of this item is:" << price << endl;
    }
};

int main()
{
    int size = 2;
    ShopItem *ptr = new ShopItem[size];
    ShopItem *tempptr = ptr;
    int p;
    float q;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the Id and Price of the Item:" << i + 1 << endl;
        cin >> p >> q;
        ptr->setdata(p, q);
        ptr++;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Item No:" << i + 1 << endl;
        tempptr->getdata();
        tempptr++;
    }
    return 0;
}