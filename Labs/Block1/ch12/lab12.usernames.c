/*
    Programmer: Grant Ogden
    Date: 2/25/2018
    Filename: lab12.usernames.c
    Reason: To better understand File IO
*/
#include <stdio.h>
#include <ctype.h>

int main()
{
    int numOfStudents;                                          //Hold the number of students are in the class
    char first[25] = {0};                                       //Holds the student's first name
    char middle[25] = {0};                                      //Holds the student's middle name
    char last[25] = {0};                                        //Holds the student's last name
    char username[27] = {0};                                    //Holds the formed username

    FILE *file_ptr;                                             //Pointer to the File where we are storing information

    file_ptr = fopen("./class_roster.txt","a");                 //Open said file to append too
    if(file_ptr != NULL)                                        //If the file open correctly
    {
        printf("Please enter how many students are on the roster: ");
        scanf("%d",&numOfStudents);                             //Get the Number of students 

        printf("Please enter student's name (first middle last) for:\n");

        //for every student
        for(int i = 0, count = 0; i < numOfStudents; i++, count = 0)
        {
            printf("Roster #%d: ",i + 1);
            scanf("%25s %25s %25s", first,middle,last);
            username[0]= tolower(first[0]);
            username[1]= tolower(middle[0]);
            while(last[count] != '\0'){
                username[count + 2] = tolower(last[count]);
                count++;
            }
            fprintf(file_ptr,"%s %c. %s has a username of %s\n",first,middle[0],last,username);
        }
    }
    else
    {
        printf("ERROR OPENING FILE");
    }
    return 0;
}
