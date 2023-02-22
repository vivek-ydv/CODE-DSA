#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream out;
    out.open("63_EofAndOpenFunction.txt");
    string st1 = "This is Vivek Yadav \nCurrenty i am learning Cpp \nI like music so much";
    out << st1;
    out.close();

    ifstream in;
    string st2;
    in.open("63_EofAndOpenFunction.txt");
    cout << "Content of the file is:->" << endl;

    while (in.eof() == 0) // while (in.eof() == false)
    {
        getline(in, st2);
        cout << st2 << endl;
    }

    return 0;
}