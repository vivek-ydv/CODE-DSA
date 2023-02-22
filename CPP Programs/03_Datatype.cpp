/*
Sample Input: 3 12345678912345 a 334.23 14049.30493

Sample Output: 3
               12345678912345
               a
               334.230
               14049.304930000
*/
#include <iostream>
#include <bits/stdc++.h> // This library includes almost all basic needed operators 
using namespace std;
int main()
{

    int n;
    long l;
    char ch;
    float f;
    double d;

    cin >> n;
    cin >> l;
    cin >> ch; 
    cin >> f;
    cin >> d;

    cout << n << "\n";
    cout << l << endl; // endl can be used in place of "\n" as a new line character operator
    cout << ch << endl;
    cout << fixed << setprecision(3) << f << endl;
    cout << fixed << setprecision(9) << d;

    return 0;
}
