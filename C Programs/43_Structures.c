#include <stdio.h>
#include <string.h>

struct Student
{
    int id;
    int marks;
    int fav_char;
    char position[10];                 
} /*vivek, vinay, harry*/;              // WE CAN ALSO DECLEARE THE MEMBERS HERE AT TIME OF INITIALISATION

// struct Student vivek, vinay, harry;  // HERE WE HAD DECLEARED GLOBALLY CAN BE USED ANTWHERE IN THE PROGRAM

int main(int argc, char const *argv[])
{
    struct Student vivek, vinay, harry; // HERE WE HAVE DECLEARED STRUCTURE MEMBERS LOCALLY HENCE CAN BE ACESSED ONLY INSIDE MAIN FUNCTION

    vivek.id = 1;                       // (.) is a dot operator, by using this structures members are acessed.
    harry.id = 2;                       // (.) is also known as "STUCTURE MEMEBER OPERATOR"
    vinay.id = 2;

    vivek.marks = 95;
    vinay.marks = 92;
    harry.marks = 94;

    vivek.fav_char = 'v';
    vinay.fav_char = 's';
    harry.fav_char = 'h';

    strcpy(vivek.position, "First");
    strcpy(vinay.position, "Second");
    strcpy(harry.position, "Third");

    printf("vivek have: id: %d, marks: %d, fav_char: %c, position: %s \n", vivek.id, vivek.marks, vivek.fav_char, vivek.position);
    printf("vinay have: id: %d, marks: %d, fav_char: %c, position: %s \n", vinay.id, vinay.marks, vinay.fav_char, vinay.position);
    printf("harry have: id: %d, marks: %d, fav_char: %c, position: %s \n", harry.id, harry.marks, harry.fav_char, harry.position);

    return 0;
}