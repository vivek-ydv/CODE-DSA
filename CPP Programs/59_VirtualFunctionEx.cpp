#include <iostream>
using namespace std;

class CWH
{
protected:
    string title;
    float rating;

public:
    CWH(string s, float r)
    {
        title = s;
        rating = r;
    }
    virtual void display() {}
};
class CWHVideo : public CWH
{
    float vlen;

public:
    CWHVideo(string s, float r, float vl) : CWH(s, r)
    {
        vlen = vl;
    }
    void display()
    {
        cout << "This is an amazing video tutorial with title " << title << endl;
        cout << "Rating: " << rating << endl;
        cout << "Length of this video is: " << vlen << endl;
    }
};
class CWHText : public CWH
{
    float wc;

public:
    CWHText(string s, float r, int txt) : CWH(s, r)
    {
        wc = txt;
    }
    void display()
    {
        cout << endl << "This is an amazing text tutorial with title " << title << endl;
        cout << "Rating: " << rating << endl;
        cout << "Number of the words in text tutorial is: " << wc << endl;
    }
};
int main()
{
    string title;
    float rating, vlen;
    int txt;

    // For video tutorial

    title = "CPP Tutorial";
    rating = 4.95;
    vlen = 4.89;
    CWHVideo cppvideo(title, rating, vlen);

    // For text tutorial

    title = "CPP Tutorial(Text Version)";
    rating = 4.65;
    txt = 495;
    CWHText cpptext(title, rating, txt);

    // Declearing pointer of base class and pointing them to the derived class and calling display function
    CWH *tuts[2];
    tuts[0] = &cppvideo;
    tuts[1] = &cpptext;
    tuts[0]->display();
    tuts[1]->display();

    return 0;
}