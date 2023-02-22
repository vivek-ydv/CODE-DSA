// Similer to structure the difference is that in "STRUCTURE EACH MEMEBER HAS ITS OWN STORAGE LOCATION"
// whereas in the "UNION EACH MEMBER USES A 'SINGLE SHARED LOCATION' = Size of latgest data member"

#include <stdio.h>
#include <string.h>

union Student
{
    int id;
    int marks;
    int fav_char;
    char position[10];

};

    int main(int argc, char const *argv[])
    {
        union Student vivek, vinay, harry;  // Union Share a single memory location with each datatype and allocate memory to thst data which is written in the last
        
        vivek.id = 1;
        vinay.id = 2; 
        harry.id = 3; 

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
