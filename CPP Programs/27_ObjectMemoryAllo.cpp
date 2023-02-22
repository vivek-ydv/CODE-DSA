#include <iostream>
using namespace std;

class Shop
{
    // It is Good practice to make all Variables private and Functions(Setter/Getter) public
private:
    int ItemId[100];
    int itemPrice[100];
    int counter;

public:
    void initcounter(void)
    {
        counter = 0;
    }
    void setprice(void);     // Setter fn
    void displayprice(void); // Getter fn
};

void Shop::setprice(void)
{
    cout << "Enter the id of your  product no " << counter + 1 << endl;
    cin >> ItemId[counter];
    cout << "Enter the price of your prodct" << endl;
    cin >> itemPrice[counter];
    counter++;
}
void Shop ::displayprice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of your product with Id " << ItemId[i] << " is " << itemPrice[i] << endl;
    }
}

int main()
{
    Shop data;
    data.initcounter();
    for (int i = 0; i < 3; i++)
    {
        data.setprice();
    }
    data.displayprice();

    return 0;
}