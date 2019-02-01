#include<stdio.h>
// first
int computerScienceCourses [] = {1003, 1023, 1033, 1063, 1073};

// second
float studentGPAs [] = {2.7, 3.1, 2.9, 4, 3.9, 2.89, 3.55};

// third
char cardinalDirections [4] = {0};

// fourth
char catchPharse [10] = {76, 101, 103, 101, 111};

int main()
{
    for(int i = 0; i < sizeof(computerScienceCourses)/sizeof(int); i++)
    {
        printf("Course Number: %d\n", computerScienceCourses[i]);
    }
    
    for(int i = 0; i < sizeof(studentGPAs)/sizeof(float); i++)
    {
        printf("Student GPA: %f\n", studentGPAs[i]);
    }

    for(int i = 0; i < sizeof(cardinalDirections)/sizeof(char); i++)
    {
        printf("Cardinal Direction: %c\n", cardinalDirections[i]);
    }

        for(int i = 0; i < sizeof(catchPharse)/sizeof(char); i++)
    {
        printf("catchPharse: %d\n", catchPharse[i]);
    }

    return 0;
}