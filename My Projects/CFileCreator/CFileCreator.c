/*
    Programmer: Grant Ogden
    Date: 2/14/2019
    Project: C File Creator
    Reason: To be lazy and have a program create my files for me
*/
#include <stdio.h>                                  //included for file input
#include <string.h>                                 //included for strlen function
#include <ctype.h>                                  //included for toupper function
#include <time.h>                                   //included to get current date
#include <sys/stat.h>                               //included to see if a dir exists and if not make one
#include <sys/types.h>                              //included to see if a dir exists and if not make one

//Error Numbers Defined
#define ERR_NULL_POINTER (-1)
#define ERR_FILE_IO (-2)
#define ERR_FILE_PATH_LENGTH (-3)

//Common Important Numbers
#define MAX_FILE_PATH_LENGTH (260)
#define MAX_FILE_NAME_LENGTH (50)

char globalFilePath[310] = {0};                     //Holds the file path
char globalFileName[50] = {0};                      //Holds the file name
FILE *fp;                                           //File Pointer used to open and create files

extern int write_main_c_file()
{
    time_t now = time(NULL);                        //set the time to now
    struct tm tm = *localtime(&now);                //assign that time to the struct
    
    //print the basic file layout into the file
    fprintf(fp,"/*\n\tProgrammer: Grant Ogden\n\tDate: %d-%d-%d\n\tProject:%s\n\tReason:\n*/\n",tm.tm_mon + 1,tm.tm_mday,tm.tm_year + 1900,globalFilePath);
    fprintf(fp,"#include <stdio.h>\n\nint main()\n{\n\t//Variable Decleration\n\n");
    fprintf(fp,"\t//Functions called here\n\n\treturn 0;\n}");

    fclose(fp);                                     //close the file
    printf("Main.c Completed\n");
    return 0;                                       //return 0 on no error
}

extern int open_file(char fileType)
{
    char tempArray[310] = {0};                      //tempArray holds the new file path for the exact file being opened

    //Copy globalFilePath to tempArray
    for(int i = 0; i < strlen(globalFilePath); i++)
    {
        tempArray[i] = globalFilePath[i];
    }
    
    switch (fileType)                               //based on the passed fileType create that file and open it for writing
    {
        case 'm':                                   //case 'm' create and open the Main.c file
            //Add Main.c to the end of the tempArray
            tempArray[strlen(tempArray)] = 'M';
            tempArray[strlen(tempArray)] = 'a';
            tempArray[strlen(tempArray)] = 'i';
            tempArray[strlen(tempArray)] = 'n';            
            tempArray[strlen(tempArray)] = '.';
            tempArray[strlen(tempArray)] = 'c';
            //Open file into fp and notify user
            fp = fopen(tempArray,"w");
            printf("Main.c Opened\n");
            break;
        case 'h':                                   //case 'h' create and open the .h file
            //add the file name to tempArray
            for(int i = strlen(tempArray),x = 0; i < (strlen(tempArray) + strlen(globalFileName)); i++,x++)
            {
                tempArray[i] = globalFileName[x];
            }
            tempArray[strlen(tempArray)] = '.';
            tempArray[strlen(tempArray)] = 'h';
            //Open file into fp and notify user
            fp = fopen(tempArray,"w");
            printf("%s.h Opened\n",globalFileName);
            break;
        case 'c':                                   //case 'c' create and open the .c file
            //add the file name to tempArray
            for(int i = strlen(tempArray),x = 0; i < (strlen(tempArray) + strlen(globalFileName)); i++,x++)
            {
                tempArray[i] = globalFileName[x];
            }
            tempArray[strlen(tempArray)] = '.';
            tempArray[strlen(tempArray)] = 'c';
            //Open file into fp and notify user
            fp = fopen(tempArray,"w");
            printf("%s.c Opened\n",globalFileName);
            break;
        default:                                    //default print error
            printf("File open error");
            break;
    }
    if(fp == NULL)                                  //if the file didn't open correctly
    {
        return ERR_FILE_IO;                         //return ERR_FILE_IO
    }
    
    return 0;                                       //return 0 upon success
}

extern int write_h_files()
{
    char nameArry[strlen(globalFileName)];          //nameArry is used to create the name for the #ifdef and #define text
    
    //Assign globalFileName to nameArry
    for(int i = 0; i < strlen(globalFileName); i++)
    {
        nameArry[i] = globalFileName[i];
    }

    //For every lettter in name Array
    for(int i = 0; i < strlen(nameArry); i++)
    {
        if(nameArry[i] >= 97 && nameArry[i] <= 122) //If it is lower case
        {
            nameArry[i] = toupper(nameArry[i]);     //Then make it upper case
        }
        else if(nameArry[i] == ' ')                 //If it is a space
        {
            nameArry[i] = '_';                      //Then make it an underscore
        }
        else if(nameArry[i] == '.')                 //If it is a period
        {
            //For every letter passed the period
            for(int j = i; j < strlen(nameArry); j++)
            {
                nameArry[j] = 0;                    //Make it equal to know
            }
            break;                                  //Break out of the loop
        }
    }

    time_t now = time(NULL);                        //Grab the time to now
    struct tm tm = *localtime(&now);                //Assign the time to the struct to access it

    //Print the format into the file
    fprintf(fp,"/*\n\tProgrammer: Grant Ogden\n\tDate: %d-%d-%d\n\tProject:%s\n\tReason:\n*/\n",tm.tm_mon + 1,tm.tm_mday,tm.tm_year + 1900,globalFilePath);
    fprintf(fp,"#ifndef %s\n",nameArry);
    fprintf(fp,"#define %s\n\n\n",nameArry);
    fprintf(fp,"/*\n * FUNCTION:\t\n * ARGUEMENTS:\t\n * RETURN:\t\t\n * NOTES:\t\t\n */\n\n\n");
    fprintf(fp,"#endif");

    fclose(fp);                                     //Close the header file
    printf("%s.h Completed\n",globalFileName);      //Notify the user of completion

    open_file('c');                                 //Open corresponding .c file

    //Print the format into the file
    fprintf(fp,"/*\n\tProgrammer: Grant Ogden\n\tDate: %d-%d-%d\n\tProject:%s\n\tReason:\n*/\n",tm.tm_mon + 1,tm.tm_mday,tm.tm_year + 1900,globalFilePath);

    fclose(fp);                                     //Close the header c file
    printf("%s.c Completed\n",globalFileName);      //Notify the user of completion

    return 0;                                       //Return 0 on success
}


extern int save_file_path(char * filePath,char * fileName)
{
    //For every letter in passed filePath
    for(int i = 0; i < strlen(filePath); i++)
    {
        //Assign it to globalFilePath
        globalFilePath[i] = filePath[i];
    }
    //For every letter in fileName starting at the end of filePath
    for(int i = strlen(filePath),x = 0; i < (strlen(fileName)+strlen(filePath)); i++,x++)
    {
        //Assign it to the end of globalFilePath
        globalFilePath[i] = fileName[x];
    }
    //Assign an extra slash because it is a directory
    globalFilePath[strlen(globalFilePath)] = '/';
    //For every letter in fileName
    for(int i = 0; i < strlen(fileName); i++)
    {
        //Assign to globalFileName
        globalFileName[i] = fileName[i];
    }

    return 0;                                       //Return 0 on success
}


extern int create_project(char *filePath,char * fileName)
{
    struct stat st = {0};                           //A stat struct used to check if file exists

    if(!filePath || !fileName)                      //If filePath or fileName are Null
    {
        return ERR_NULL_POINTER;                    //Then return ERR_NULL_POINTER
    }
    else if(strlen(filePath) == 0 || strlen(filePath) >= 260)   //If filePath is empty or too long
    {
        return ERR_FILE_PATH_LENGTH;                //Then return ERR_FILE_PATH_LENGTH
    }

    save_file_path(filePath,fileName);              //Save the file path and name for use

    if(stat(globalFilePath,&st) == -1)              //If the dir doesn't exist
    {
        mkdir(globalFilePath,0700);                 //Make the dir
    }
    open_file('m');                                 //Open Main.c file
    write_main_c_file();                            //Write Main.c file
    open_file('h');                                 //Open header files
    write_h_files();                                //Write header files
    return 0;                                       //Return 0 on success
}