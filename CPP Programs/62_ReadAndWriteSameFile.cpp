#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string st;
    ofstream fileout("62_ReadAndWriteSameFile.txt");
    cout << "Input your name: ";
    cin >> st;
    fileout << "Your name is " + st;
    fileout.close();

    string content;
    ifstream filein("62_ReadAndWriteSameFile.txt");
    // filein >> st;
    // cout << st;
    getline(filein, content);
    cout<<"The content of this file is : "<< content;
    filein.close();
    return 0;
}
