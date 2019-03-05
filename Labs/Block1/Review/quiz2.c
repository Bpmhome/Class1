/*
    Programmer: Grant Ogden
    Date: 3/5/2019
    Filename: quiz2.c
    Reason: To better understand conditional inside loops and flow control.

    Instruction: A class of ten students took a quiz. The grade (integers in the range 0 to 100)for
    this quiz are available to you. Determine the class averae on the quiz.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int grade;
    struct student *next;
}student_t;

void add_student(student_t * head, int grade);

int main()
{
    student_t *head = (student_t*)malloc(sizeof(student_t));
    int average = 0;
    int numberOfStudents = 0;

    printf("Welcome to the student grade counter!\n\n");

    printf("How many students are in your class: ");
    scanf("%d",&numberOfStudents);

    for(int i = 0, grade = 0; i < numberOfStudents; i++)
    {
        printf("Please enter the grade for student #%d:\t",i+1);
        scanf("%d", &grade);
        if(grade < 0 || grade > 100)
        {
            printf("Grades can only be between 0 and 100\n");
            i--;
            continue;
        }
        average += grade;
        add_student(head,grade);

        printf("Current Average: %.3f\n\n", ((float)average / (i + 1)));
    }

    printf("\nThe Class Average is: %.3f\n", (float)average / numberOfStudents);
    
    return 0;
}

void add_student(student_t *head, int grade)
{
    student_t *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = (student_t*)malloc(sizeof(student_t));
    current->grade = grade;
}