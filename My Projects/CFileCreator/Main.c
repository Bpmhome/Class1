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
    char filePath[MAX_FILE_PATH_LENGTH] = {0};
    char fileName[MAX_FILE_NAME_LENGTH] = {0};
    int error = 0;

    printf("Please enter file path:\n");
    fscanf(stdin,"%260[^\n]c",filePath);
    clear_input();
    printf("Please enter file name:\n");
    fscanf(stdin,"%50[^\n]c",fileName);

    error = open_file(filePath,fileName);
    create_project(filePath,fileName);
    printf("%d",error);
    return 0;
}


void clear_input()
{
    while( getchar() != '\n');
}