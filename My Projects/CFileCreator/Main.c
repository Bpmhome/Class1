/*
    Programmer: Grant Ogden
    Date: 2/14/2019
    Project: C File Creator
    Reason: To be lazy and have a program create my files for me
*/
#include <stdio.h>
#include "CFileCreator.h"

void clear_input();

int main()
{
    char filePath[MAX_FILE_PATH_LENGTH] = {0};  //Holds the user's file path
    char fileName[MAX_FILE_NAME_LENGTH] = {0};  //Holds the user's file name

    printf("Please enter file path:\n");        //Ask the user for their file path
    fscanf(stdin,"%260[^\n]c",filePath);        //Get the user file path
    clear_input();                              //Clear User input
    printf("Please enter file name:\n");        //Ask the user for their file name
    fscanf(stdin,"%50[^\n]c",fileName);         //Get the user file name

    create_project(filePath,fileName);          //Create the project
    return 0;
}


void clear_input()
{
    while( getchar() != '\n');
}