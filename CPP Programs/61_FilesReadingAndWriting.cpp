#include <iostream>
#include <fstream>
/*
The useful classes for working with files in c++ are :
1. fstreambase
2. ifstream --> derived from fstreambase 
3. ofstream --> derived from fstreambase

In order to work with files in C++, you will have to open it. Primarily there are two ways to open a file :->
1. Using the constructor.
2. Using the member function open() of the class.
*/

using namespace std;
int main()
{
    // Opening files using constructor and Writing it --
    string st1 = "Hello! This is Vivek Yadav";
    ofstream outfile("61_FilesReadingAndWriting.txt"); 
    outfile << st1;
    outfile.close();

    // Opening files using constructor and Reading it --
    string st2;
    ifstream infile("61_FilesReadingAndWriting2.txt");
    // infile >> st2;     // It will not read the whole line, only read the file till the first space found.
    // cout << st2 << endl;
    getline(infile, st2); // It will read the the complte 1st line.
    cout << st2 << endl;
    getline(infile, st2); // It will read the the complte 2nd line, as many time we will run it, it will read the next line from that file.
    cout << st2 << endl;
    infile.close();
    return 0;
}