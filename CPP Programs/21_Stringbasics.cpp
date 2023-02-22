#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str1, str2;
    char temp;

    cout << "Input the 2 string" << endl;

    cin >> str1 >> str2;
    int len1 = str1.size();
    int len2 = str2.length();
    string str3 = str1 + str2;

    temp = str1[0];
    str1.at(0) = str2[0]; // By using both methods we can acess the elements of string
    str2[0] = temp;

    cout << "Size of inputted strings are: " << len1 << " and " << len2 << endl;
    cout << "After adding the two string: " << str3 << endl;
    cout << "After replacing first word of each other: " << str1 << " " << str2;

    return 0;
}
