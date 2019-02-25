/*
    Programmer: Grant Ogden
    Date: 2/5/2019
    Filename: lab.your_song.c
    Reason: to better understand File IO
*/
#include<stdio.h>

int main()
{
    char input[100];                            //holds a line from the file
    FILE *file_ptr;                             //holds the pointer to the file

    //opens the file
    file_ptr = fopen("/home/student/Class/Class1/Labs/Block1/ch12/The House Fire.txt","r");

    if(file_ptr != NULL)                        //Make sure the file open correctly
    {
        while(!feof(file_ptr))                  //While we are not at the end of the file repeat
        {
            fgets(input,100,file_ptr);          //Pull a line
            printf("%s",input);                 //Print that line
        }
        printf("\n");                           //New line for terminal spacing
        fclose(file_ptr);                       //close the file stream
    }
    else
    {
        printf("FILE ERROR");                   //if it isnt open print error
    }

    return 0;
}
