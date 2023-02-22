#include <iostream>
using namespace std;

void subSeq(string p, string up)
{
    if (up.empty())
    {
        cout << "[" << p << "]";
        return;
    }
    subSeq(p + up.at(0), up.substr(1));
    subSeq(p, up.substr(1));
}
int main()
{

    string p;          // p: processed string, initially empty
    string up = "abc"; // up: unprocessed string
    subSeq(p, up);
    return 0;
}
