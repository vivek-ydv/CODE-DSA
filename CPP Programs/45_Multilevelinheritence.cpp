#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int);
    void get_roll_number(void);
};
void Student::set_roll_number(int r)
{
    roll_number = r;
}
void Student::get_roll_number()
{
    cout << "The roll number is: " << roll_number << endl;
}

class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void Set_marks(float, float);
    void Get_marks();
};
void Exam::Set_marks(float m1, float m2)
{
    maths = m1;
    physics = m2;
}
void Exam::Get_marks()
{
    cout << "The marks obtained in physics are: " << physics << endl;
    cout << "The marks obtained in maths are: " << maths << endl;
}

class Result : public Exam
{
public:
       void Display_percentage()
    {
        get_roll_number();
        Get_marks();

        cout << "Your percentage is: " << (physics + maths) / 2 << "%" << endl;
    }
};

int main()
{
    Result vivek;
    vivek.set_roll_number(29);
    vivek.Set_marks(95, 92);
    vivek.Display_percentage();
    return 0;
}
/*
NOTES:
      If we are inheriting B from A and C from B:[A-->B-->C]
      1.A is the base class of B and B is the base class of C.
      2.ABC is called inheritence path.
*/