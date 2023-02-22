#include <iostream>
using namespace std;
class Student
{
protected:
    int roll_no;

public:
    void set_number(int a)
    {
        roll_no = a;
    }
    void print_number()
    {
        cout << "Your roll number is:" << roll_no << endl;
    }
};
/*
When one class is made virtual then only one copy of its data member and member function is passed to the classes inheriting it.
So in our example when we will make class “Student” a virtual class then only one copy of data member and member function will be
passed to the classes “Test” and “Sports” which will be shared between all classes. This will help to solve the ambiguity.
*/
class Test : virtual public Student
{
protected:
    float maths, physics;

public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }
    void print_marks()
    {
        cout << "Your result is here" << endl
             << "Maths:" << maths << endl
             << "Physics:" << physics << endl;
    }
};
class Sports : virtual public Student
{
protected:
    float score;

public:
    void set_score(float sc)
    {
        score = sc;
    }
    void print_score()
    {
        cout << "Your PT score is:" << score << endl;
    }
};
class Result : public Test, public Sports
{
private:
    float total;

public:
    void display()
    {
        total = maths + physics + score;
        print_number();
        print_marks();
        print_score();
        cout << "Your total score is:" << total << endl;
    }
};
int main()
{
    Result vivek;
    vivek.set_number(29);
    vivek.set_marks(92.7, 95.5);
    vivek.set_score(9.2);
    vivek.display();
    return 0;
}