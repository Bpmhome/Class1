/*
    Programmer: Grant Ogden
    Date: 3/5/2019
    Filename: quiz4.c
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
    int pass,fail;
    int numberOfStudents = 0;
    pass = fail = 0;

    printf("Welcome to the student grade counter!\n\n");

    printf("How many students are in your class: ");
    scanf("%d",&numberOfStudents);

    for(int i = 0, grade = 0; i < numberOfStudents; i++)
    {
        printf("Enter Result (1 = pass 2 = fail):\t",i+1);
        scanf("%d", &grade);
        if(grade <= 0 || grade >= 3)
        {
            printf("Grades can only be 1 or 2\n");
            i--;
            continue;
        }
        if(grade == 1)
        {
            pass++;
        }
        else
        {
            fail++;
        }
        
        add_student(head,grade);

    }

    printf("\nPassed %d\n",pass);
    printf("Failed %d\n",fail);
    if(pass >= numberOfStudents*.8)
    {
        printf("Bonus to instructor!\n");
    }
    
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